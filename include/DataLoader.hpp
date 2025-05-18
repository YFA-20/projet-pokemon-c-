#pragma once
#include <string>
#include <vector>
#include <map>

class Pokemon;
class Joueur;
class LeaderGym;
class MaitrePokemon;

struct DataLoader {
  // Charge tous les Pokémons (et crée les Types et Attaques associés)
  static std::map<std::string,Pokemon*> loadPokemons(const std::string& filename);

  // Charge le joueur (Joueur.csv)
  static Joueur* loadPlayer(const std::string& filename,
                            const std::map<std::string,Pokemon*>& pokedex);

  // Charge les leaders de gym (Leaders.csv)
  static std::vector<LeaderGym*> loadLeaders(const std::string& filename,
                                             const std::map<std::string,Pokemon*>& pokedex);

  // Charge les maîtres (Maitres.csv)
  static std::vector<MaitrePokemon*> loadMasters(const std::string& filename,
                                                 const std::map<std::string,Pokemon*>& pokedex);
};

