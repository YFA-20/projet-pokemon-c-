#include "MenuPrincipal.hpp"
#include "Combat.hpp"
#include <iostream>

void lancerMenuPrincipal(Joueur* joueur,
                         const std::vector<LeaderGym*>& leaders,
                         const std::vector<MaitrePokemon*>& masters)
{
    while (true) {
        // --- Affichage du menu des gymnases ---
        std::cout << "\n=== Choisis un gymnase ===\n";
        for (size_t i = 0; i < leaders.size(); ++i) {
            std::cout << "  " << (i + 1) << ") "
                      << leaders[i]->getNom()
                      << " [Badge " << leaders[i]->getBadgeName() << "]\n";
        }
        std::cout << "  0) Quitter\n";
        std::cout << "Ton choix> ";

        int choix;
        if (!(std::cin >> choix)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrée invalide, réessaie.\n";
            continue;
        }
        if (choix == 0) {
            std::cout << "Au revoir !\n";
            return;
        }
        if (choix < 1 || choix > int(leaders.size())) {
            std::cout << "Hors liste, réessaie.\n";
            continue;
        }

        // --- Lancement du combat contre le leader choisi ---
        LeaderGym* lg = leaders[choix - 1];
        std::cout << "\nDébut du combat entre Toi et " 
                  << lg->getNom() << " !\n\n";

        Combat combat(joueur, lg);
        combat.demarrer();

        // Vérifie si le joueur a perdu (plus aucun Pokémon dispo)
        if (! joueur->aPokemonDisponible()) {
            std::cout << "Tu as perdu tous tes Pokémon. Fin du jeu.\n";
            return;
        }

        // Sinon, le joueur a gagné le badge
        std::cout << "Bravo ! Tu obtiens le badge " 
                  << lg->getBadgeName() << " 🏅\n";

        // (Optionnel : on pourrait ensuite proposer d'affronter un maître…)
    }
}

