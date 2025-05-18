#include "DataLoader.hpp"

#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"

#include <fstream>
#include <sstream>

using namespace std;

map<string, Type*> DataLoader::loadTypes(const string& filename) {
    map<string, Type*> types;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        types[line] = new Type(line);
    }
    return types;
}

map<string, Attack*> DataLoader::loadAttacks(const string& filename,
                                             const map<string, Type*>& types) {
    map<string, Attack*> attacks;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, power_s, type_s;
        getline(ss, name, ',');
        getline(ss, power_s, ',');
        getline(ss, type_s, ',');
        int power = stoi(power_s);
        auto it = types.find(type_s);
        if (it != types.end())
            attacks[name] = new Attack(name, power, it->second);
    }
    return attacks;
}

map<string, Pokemon*> DataLoader::loadPokemons(const string& filename,
                                               const map<string, Type*>& types,
                                               const map<string, Attack*>& attacks) {
    map<string, Pokemon*> pokedex;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, hp_s, types_s, attacks_s;
        getline(ss, name, ',');
        getline(ss, hp_s, ',');
        getline(ss, types_s, ',');
        getline(ss, attacks_s, ',');
        int hp = stoi(hp_s);

        vector<Type*> tv;
        string tname;
        stringstream st(types_s);
        while (getline(st, tname, ';')) {
            auto it = types.find(tname);
            if (it != types.end())
                tv.push_back(it->second);
        }

        vector<Attack*> av;
        string aname;
        stringstream sa(attacks_s);
        while (getline(sa, aname, ';')) {
            auto it2 = attacks.find(aname);
            if (it2 != attacks.end())
                av.push_back(it2->second);
        }

        pokedex[name] = new Pokemon(name, hp, tv, av);
    }
    return pokedex;
}

Joueur* DataLoader::loadPlayer(const string& filename,
                               const map<string, Pokemon*>& pokedex) {
    ifstream in(filename);
    string line;
    if (!getline(in, line)) return nullptr;

    stringstream ss(line);
    string tmp;
    getline(ss, tmp, ','); // on skip le nom "joueur"
    string pname;
    vector<Pokemon*> team;
    while (getline(ss, pname, ',')) {
        auto it = pokedex.find(pname);
        if (it != pokedex.end())
            team.push_back(it->second);
    }
    return new Joueur(tmp, team);
}

vector<LeaderGym*> DataLoader::loadLeaders(const string& filename,
                                           const map<string, Pokemon*>& pokedex) {
    vector<LeaderGym*> out;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, gymid_s, badge;
        getline(ss, name, ',');
        getline(ss, gymid_s, ',');
        getline(ss, badge, ',');
        int gymId = stoi(gymid_s);

        vector<Pokemon*> team;
        string pname;
        while (getline(ss, pname, ',')) {
            auto it = pokedex.find(pname);
            if (it != pokedex.end())
                team.push_back(it->second);
        }
        out.push_back(new LeaderGym(name, team, gymId, badge));
    }
    return out;
}

vector<MaitrePokemon*> DataLoader::loadMasters(const string& filename,
                                               const map<string, Pokemon*>& pokedex) {
    vector<MaitrePokemon*> out;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name;
        getline(ss, name, ',');
        vector<Pokemon*> team;
        string pname;
        while (getline(ss, pname, ',')) {
            auto it = pokedex.find(pname);
            if (it != pokedex.end())
                team.push_back(it->second);
        }
        out.push_back(new MaitrePokemon(name, team));
    }
    return out;
}

