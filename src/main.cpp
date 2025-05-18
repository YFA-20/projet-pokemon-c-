#include <iostream>
#include "DataLoader.hpp"
#include "Combat.hpp"
#include "Type.hpp"
#include "Attack.hpp"
#include "Pokemon.hpp"
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"

int main() {
    // 1) Chargement des données
    auto types   = DataLoader::loadTypes("types.csv");
    auto attacks = DataLoader::loadAttacks("attacks.csv", types);
    auto pokedex = DataLoader::loadPokemons("pokemon.csv", types, attacks);

    auto joueur  = DataLoader::loadPlayer("joueur.csv", pokedex);
    auto leaders = DataLoader::loadLeaders("leaders.csv", pokedex);
    auto masters = DataLoader::loadMasters("maitres.csv", pokedex);

    // 2) Affichage rapide de l'état
    std::cout << "✅ Pokedex chargé : " << pokedex.size() << " Pokémon\n";

    std::cout << "✅ Joueur \"" << joueur->getNom() << "\" équipe :\n";
    for (auto* p : joueur->getEquipe()) {
        std::cout << "   - " << p->getNom()
                  << " (" << p->getPV() << " PV)\n";
    }

    std::cout << "\n✅ Leaders disponibles :\n";
    for (auto* lg : leaders) {
        std::cout << "   - " << lg->getNom()
                  << " (Gym n°" << lg->getGymId() << ")"
                  << " [Badge " << lg->getBadgeName() << "]\n";
    }

    // 3) Lancer un combat exemple contre le 1er leader
    Combat combat(joueur, leaders.front());
    combat.demarrer();

    return 0;
}

