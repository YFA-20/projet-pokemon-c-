#include "DataLoader.hpp"
#include "Pokemon.hpp"
#include "Attack.hpp"
#include "Type.hpp"
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

map<string,Pokemon*> DataLoader::loadPokemons(const string& filename) {
    map<string,Pokemon*> pokedex;
    map<string,Type*>    types;
    map<string,Attack*>  attacks;

    ifstream file(filename);
    if (!file) {
        cerr << "Erreur: impossible d'ouvrir " << filename << "\n";
        return {};
    }

    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        stringstream ss(line);
        string name, t1, t2, pvStr, atkName, atkPowStr;
        getline(ss, name, ',');
        getline(ss, t1,   ',');
        getline(ss, t2,   ',');
        getline(ss, pvStr,',');
        getline(ss, atkName,',');
        getline(ss, atkPowStr);

        int pv    = stoi(pvStr);
        int powAt = stoi(atkPowStr);

        // --- Types ---
        vector<Type*> vtypes;
        if (!t1.empty()) {
          if (!types.count(t1)) types[t1] = new Type(t1);
          vtypes.push_back(types[t1]);
        }
        if (!t2.empty()) {
          if (!types.count(t2)) types[t2] = new Type(t2);
          vtypes.push_back(types[t2]);
        }

        // --- Attaque unique (on stocke une seule attaque par Pokémon pour l'instant) ---
        if (!attacks.count(atkName)) {
          // on associe l'attaque à son type principal
          attacks[atkName] = new Attack(atkName, powAt, types[t1]);
        }
        vector<Attack*> vatk = { attacks[atkName] };

        pokedex[name] = new Pokemon(name, pv, vtypes, vatk);
    }
    return pokedex;
}

Joueur* DataLoader::loadPlayer(const string& filename,
                               const map<string,Pokemon*>& pokedex) {
    ifstream file(filename);
    if (!file) {
      cerr << "Erreur: impossible d'ouvrir " << filename << "\n";
      return nullptr;
    }
    string line, header;
    getline(file, header);
    if (!getline(file, line)) return nullptr;

    stringstream ss(line);
    string name, pokeName;
    vector<Pokemon*> team;
    getline(ss, name, ',');
    while (getline(ss, pokeName, ',')) {
      if (pokedex.count(pokeName))
        team.push_back(pokedex.at(pokeName));
    }
    return new Joueur(name, team);
}

vector<LeaderGym*> DataLoader::loadLeaders(const string& filename,
                                           const map<string,Pokemon*>& pokedex) {
    ifstream file(filename);
    if (!file) {
      cerr << "Erreur: impossible d'ouvrir " << filename << "\n";
      return {};
    }
    string line, header;
    getline(file, header);
    vector<LeaderGym*> result;
    int gymId = 1;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, gymName, badge;
        getline(ss, name, ',');
        getline(ss, gymName, ',');
        getline(ss, badge, ',');
        vector<Pokemon*> team;
        string pokeName;
        while (getline(ss, pokeName, ',')) {
          if (pokedex.count(pokeName))
            team.push_back(pokedex.at(pokeName));
        }
        result.push_back(new LeaderGym(name, team, gymId++, badge));
    }
    return result;
}

vector<MaitrePokemon*> DataLoader::loadMasters(const string& filename,
                                               const map<string,Pokemon*>& pokedex) {
    ifstream file(filename);
    if (!file) {
      cerr << "Erreur: impossible d'ouvrir " << filename << "\n";
      return {};
    }
    string line, header;
    getline(file, header);
    vector<MaitrePokemon*> result;

    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        getline(ss, name, ',');
        vector<Pokemon*> team;
        string pokeName;
        while (getline(ss, pokeName, ',')) {
          if (pokedex.count(pokeName))
            team.push_back(pokedex.at(pokeName));
        }
        result.push_back(new MaitrePokemon(name, team));
    }
    return result;
}

