#include "MenuPrincipal.hpp"
#include "Combat.hpp"
#include <iostream>
#include <set>

// -----------------------------------------------------------------------------
// Affiche le menu « hors‐combat » pour consulter son équipe / ses stats, etc.
// Appelé quand on rechoisit un gym déjà gagné.
// -----------------------------------------------------------------------------
static void afficherMenuHorsCombat(Joueur* joueur) {
    while (true) {
        std::cout
          << "\n" << joueur->getNom() << ", à toi de jouer (hors-combat) !\n"
          << "1) Afficher mes Pokémon\n"
          << "2) Attaquer (non disponible)\n"
          << "3) Changer de Pokémon (non disponible)\n"
          << "4) Afficher PV de l’équipe\n"
          << "5) Réorganiser l’ordre des Pokémon (non disponible)\n"
          << "6) Afficher mes statistiques\n"
          << "7) Interagir avec KO/vaincus\n"
          << "0) Retour\n"
          << "Choix> " << std::flush;

        int c;
        if (!(std::cin >> c)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        switch (c) {
          case 0:
            return;
          case 1:
            joueur->afficherMesPokemons();
            break;
          case 4:
            joueur->afficherPvEquipe();
            break;
          case 6:
            joueur->afficherStatistiques();
            break;
          case 7:
            joueur->interagirKOvaincus();
            break;
          default:
            std::cout << "Option non disponible ici.\n";
        }
    }
}

// -----------------------------------------------------------------------------
// Lance le menu de choix de gymnase, gère badges et retours hors-combat.
// -----------------------------------------------------------------------------
void lancerMenuPrincipal(Joueur* joueur,
                         const std::vector<LeaderGym*>& leaders,
                         const std::vector<MaitrePokemon*>& masters)
{
    std::set<int> badgesObtenus;

    while (true) {
        // --- Affichage du menu des gymnases ---
        std::cout << "\n=== Choisis un gymnase ===\n";
        for (size_t i = 0; i < leaders.size(); ++i) {
            std::cout << "  " << (i+1) << ") "
                      << leaders[i]->getNom()
                      << " [Badge " << leaders[i]->getBadgeName() << "]\n";
        }
        std::cout << "  0) Quitter\n"
                  << "Ton choix> " << std::flush;

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

        int idx = choix - 1;
        // Si déjà battu, on bascule hors-combat
        if (badgesObtenus.count(idx)) {
            afficherMenuHorsCombat(joueur);
            continue;
        }

        // --- Lancement du combat contre le leader choisi ---
        LeaderGym* lg = leaders[idx];
        std::cout << "\nDébut du combat entre Toi et "
                  << lg->getNom() << " !\n\n";

        Combat combat(joueur, lg);
        combat.demarrer();

        // Si défaite, on quitte
        if (!joueur->aPokemonDisponible()) {
            std::cout << "Tu as perdu tous tes Pokémon. Fin du jeu.\n";
            return;
        }

        // Victoire : on incrémente stat, badge et on repart au menu
        joueur->enregistrerVictoire();
        joueur->gagnerBadge();
        badgesObtenus.insert(idx);

        std::cout << "Bravo ! Tu obtiens le badge "
                  << lg->getBadgeName() << " 🏅\n";
    }
}

