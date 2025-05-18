#include "Joueur.hpp"
#include <iostream>
#include <limits>

Joueur::Joueur(const std::string& nom,
               const std::vector<Pokemon*>& equipe)
  : Dresseur(nom, equipe)
{}

Action Joueur::choisirAction() {
    while (true) {
        // --- Menu principal ---
        std::cout << "\n" << getNom() << ", à toi de jouer !\n"
                  << "1) Afficher mes Pokémon\n"
                  << "2) Attaquer\n";
        if (equipe_.size() > 1)
            std::cout << "3) Changer de Pokémon\n";
        std::cout << "4) Afficher PV de l’équipe\n"
                  << "Choix> " << std::flush;

        int choix;
        if (!(std::cin >> choix)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choix = 2;  // retombe sur "Attaquer" par défaut
        }

        // --- 1) Afficher mes Pokémon ---
        if (choix == 1) {
            std::cout << "\n=== Mon Équipe Pokémon ===\n";
            for (size_t i = 0; i < equipe_.size(); ++i) {
                Pokemon* p = equipe_[i];
                std::cout << " " << (i+1) << ") "
                          << p->getNom()
                          << " | PV=" << p->getPV()
                          << " | Types=";
                for (Type* t : p->getTypes())
                    std::cout << t->getNom() << " ";
                std::cout << "| Attaques=";
                for (Attack* a : p->getAttaques())
                    std::cout << a->getNom() << " ";
                std::cout << "\n";
            }
            std::cout << "===========================\n";
            continue;  // on revient au menu
        }

        // --- 2) Attaquer ---
        if (choix == 2) {
            Pokemon* actif = getActif();
            size_t n = actif->getNbAttaques();
            std::cout << "\nSélectionne l'attaque :\n";
            for (size_t i = 0; i < n; ++i) {
                std::cout << " " << (i+1) << ") "
                          << actif->getAttaque(i)->getNom() << "\n";
            }
            std::cout << "Attaque> " << std::flush;
            int atk;
            if (!(std::cin >> atk) || atk < 1 || atk > static_cast<int>(n))
                atk = 1;
            return Action::makeAttaque(actif->getAttaque(atk-1));
        }

        // --- 3) Changer de Pokémon ---
        if (choix == 3 && aPokemonDisponible()) {
            std::cout << "\nSélectionne le Pokémon :\n";
            for (size_t i = 0; i < equipe_.size(); ++i) {
                Pokemon* p = equipe_[i];
                std::cout << " " << (i+1) << ") "
                          << p->getNom()
                          << " (" << p->getPV() << " PV)\n";
            }
            std::cout << "Pokémon> " << std::flush;
            int idx;
            if (!(std::cin >> idx) || idx < 1
                || idx > static_cast<int>(equipe_.size()))
                idx = 1;
            return Action::makeChangement(equipe_.at(idx-1));
        }

        // --- 4) Afficher PV de l’équipe ---
        if (choix == 4) {
            std::cout << "\n=== PV restants de l’équipe ===\n";
            for (size_t i = 0; i < equipe_.size(); ++i) {
                Pokemon* p = equipe_[i];
                std::cout << " " << (i+1) << ") "
                          << p->getNom()
                          << " : " << p->getPV() << " PV\n";
            }
            std::cout << "===============================\n";
            continue;  // on revient au menu
        }

        // --- Par défaut, attaquer ---
        // (retombe ici si choix invalide ou 2)
        Pokemon* actif = getActif();
        size_t n = actif->getNbAttaques();
        std::cout << "\nSélectionne l'attaque :\n";
        for (size_t i = 0; i < n; ++i) {
            std::cout << " " << (i+1) << ") "
                      << actif->getAttaque(i)->getNom() << "\n";
        }
        std::cout << "Attaque> " << std::flush;
        int atk;
        if (!(std::cin >> atk) || atk < 1 || atk > static_cast<int>(n))
            atk = 1;
        return Action::makeAttaque(actif->getAttaque(atk-1));
    }
}

