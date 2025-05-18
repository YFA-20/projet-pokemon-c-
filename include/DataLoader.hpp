#pragma once

#include <string>
#include <map>
#include <vector>

class Type;
class Attack;
class Pokemon;
class Joueur;
class LeaderGym;
class MaitrePokemon;

/// Charge toutes les données depuis des CSV
struct DataLoader {
    /// charge les Types (un nom par ligne)
    static std::map<std::string, Type*>
    loadTypes(const std::string& filename);

    /// charge les Attacks (format: nom,power,type)
    static std::map<std::string, Attack*>
    loadAttacks(const std::string& filename,
                const std::map<std::string, Type*>& types);

    /// charge les Pokémons (format: nom,HP,types(;),attaques(;))
    static std::map<std::string, Pokemon*>
    loadPokemons(const std::string& filename,
                 const std::map<std::string, Type*>& types,
                 const std::map<std::string, Attack*>& attacks);

    /// charge le Joueur (format: joueur,nom1,nom2,...)
    static Joueur* loadPlayer(const std::string& filename,
                              const std::map<std::string, Pokemon*>& pokedex);

    /// charge les LeaderGym (format: nom,gymId,badge,poke1,poke2,...)
    static std::vector<LeaderGym*>
    loadLeaders(const std::string& filename,
                const std::map<std::string, Pokemon*>& pokedex);

    /// charge les Maîtres (format: nom,poke1,poke2,...)
    static std::vector<MaitrePokemon*>
    loadMasters(const std::string& filename,
                const std::map<std::string, Pokemon*>& pokedex);
};

