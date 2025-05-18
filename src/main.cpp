#include "DataLoader.hpp"
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"
#include "MenuPrincipal.hpp"
#include <iostream>

int main() {
    std::cout << "[DEBUG] début main()\n";
    auto pokedex = DataLoader::loadPokemons("fichiers_csv/pokemon.csv");
    auto joueur  = DataLoader::loadPlayer  ("fichiers_csv/joueur.csv",   pokedex);
    auto leaders = DataLoader::loadLeaders ("fichiers_csv/leaders.csv",  pokedex);
    auto masters = DataLoader::loadMasters ("fichiers_csv/maitres.csv",  pokedex);

    // vérifications omises pour la concision…

    // ici on délègue tout le menu principal
    lancerMenuPrincipal(joueur, leaders, masters);

    return 0;
}

