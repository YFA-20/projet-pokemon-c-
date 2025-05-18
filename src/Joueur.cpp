#include "Joueur.hpp"
#include "Dresseur.hpp"
#include "Pokemon.hpp"   
#include <iostream>
#include <limits>
#include <algorithm>
#include <string>

Joueur::Joueur(const std::string& nom,
               const std::vector<Pokemon*>& equipe)
  : Dresseur(nom, equipe)
{}

Action Joueur::choisirAction() {
    while (true) {
        // --- Menu principal ---
        std::cout << "\n" << getNom() << ", à toi de jouer !\n"
                  << "1) Afficher mes Pokémon\n"
                  << "2) Attaquer\n"
                  << "3) Changer de Pokémon\n"
                  << "4) Afficher PV de l’équipe\n"
                  << "5) Réorganiser l’ordre des Pokémon\n"
                  << "6) Afficher mes statistiques\n"
                  << "7) Interagir avec KO/vaincus\n"
                  << "Choix> " << std::flush;

        int choix;
        if (!(std::cin >> choix)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choix = 2;
        }

        // 1) Afficher mes Pokémon
        if (choix == 1) {
            std::cout << "\n=== Mon Équipe Pokémon ===\n";
            for (size_t i = 0; i < equipe_.size(); ++i) {
                auto* p = equipe_[i];
                std::cout << " " << (i+1) << ") "
                          << p->getNom()
                          << " | PV=" << p->getPV()
                          << " | Types=";
                for (auto* t : p->getTypes())
                    std::cout << t->getNom() << " ";
                std::cout << "| Attaques=";
                for (auto* a : p->getAttaques())
                    std::cout << a->getNom() << " ";
                std::cout << "\n";
            }
            std::cout << "===========================\n";
            continue;
        }

        // 2) Attaquer
        if (choix == 2) {
            auto* actif = getActif();
            size_t n = actif->getNbAttaques();
            std::cout << "\nSélectionne l'attaque :\n";
            for (size_t i = 0; i < n; ++i)
                std::cout << " " << (i+1) << ") "
                          << actif->getAttaque(i)->getNom() << "\n";
            std::cout << "Attaque> " << std::flush;
            int atk;
            if (!(std::cin >> atk) || atk < 1 || atk > int(n)) atk = 1;
            return Action::makeAttaque(actif->getAttaque(atk-1));
        }

        // 3) Changer de Pokémon
        if (choix == 3 && aPokemonDisponible()) {
            std::cout << "\nSélectionne le Pokémon :\n";
            for (size_t i = 0; i < equipe_.size(); ++i)
                std::cout << " " << (i+1) << ") "
                          << equipe_[i]->getNom()
                          << " (" << equipe_[i]->getPV() << " PV)\n";
            std::cout << "Pokémon> " << std::flush;
            int idx;
            if (!(std::cin >> idx) || idx < 1 || idx > int(equipe_.size()))
                idx = 1;
            return Action::makeChangement(equipe_.at(idx-1));
        }

        // 4) Afficher PV de l’équipe
        if (choix == 4) {
            std::cout << "\n=== PV restants de l’équipe ===\n";
            for (size_t i = 0; i < equipe_.size(); ++i)
                std::cout << " " << (i+1) << ") "
                          << equipe_[i]->getNom()
                          << " : " << equipe_[i]->getPV() << " PV\n";
            std::cout << "===============================\n";
            continue;
        }

        // 5) Réorganiser l’ordre des Pokémon
        if (choix == 5 && equipe_.size() > 1) {
            std::cout << "\n=== Réorganisation de l’équipe ===\n";
            for (size_t i = 0; i < equipe_.size(); ++i)
                std::cout << " " << (i+1) << ") "
                          << equipe_[i]->getNom() << "\n";
            std::cout << "Déplacer quel Pokémon (numéro)? " << std::flush;
            int src, dst;
            std::cin >> src;
            std::cout << "Vers quelle position (1–" << equipe_.size() << ")? " << std::flush;
            std::cin >> dst;
            src = std::clamp(src, 1, int(equipe_.size()));
            dst = std::clamp(dst, 1, int(equipe_.size()));
            auto* tmp = equipe_[src-1];
            equipe_.erase(equipe_.begin() + (src-1));
            equipe_.insert(equipe_.begin() + (dst-1), tmp);
            std::cout << "Équipe mise à jour !\n";
            continue;
        }

        // 6) Afficher mes statistiques
        if (choix == 6) {
            std::cout << "\n=== Mes statistiques ===\n"
                      << " Badges    : " << getNbBadges()    << "\n"
                      << " Victoires : " << getNbVictoires() << "\n"
                      << " Défaites  : " << getNbDefaites()  << "\n"
                      << "=======================\n";
            continue;
        }

        // 7) Interagir avec KO/vaincus
        if (choix == 7) {
            // Pokémon KO
            std::cout << "\n=== Pokémon KO ===\n";
            for (auto* p : equipe_)
                if (p->estKO())
                    std::cout << " - " << p->getNom() << "\n";
            // Entraîneurs vaincus : stockés dans defeatedTrainers_ (à gérer ailleurs)
            std::cout << "\n=== Entraîneurs vaincus ===\n";
            for (auto* d : defeatedTrainers_)
                std::cout << " - " << d->getNom() << "\n";
            // Choix de la cible
            std::cout << "Interagir avec (nom exact)> " << std::flush;
            std::string cible; std::cin >> cible;
            for (auto* p : equipe_)
                if (p->getNom() == cible && p->estKO())
                    p->interagir();
            for (auto* d : defeatedTrainers_)
                if (d->getNom() == cible)
                    d->interagir();
            continue;
        }

        // Par défaut, attaquer
        {
            auto* actif = getActif();
            size_t n = actif->getNbAttaques();
            std::cout << "\nSélectionne l'attaque :\n";
            for (size_t i = 0; i < n; ++i)
                std::cout << " " << (i+1) << ") "
                          << actif->getAttaque(i)->getNom() << "\n";
            std::cout << "Attaque> " << std::flush;
            int atk;
            if (!(std::cin >> atk) || atk < 1 || atk > int(n)) atk = 1;
            return Action::makeAttaque(actif->getAttaque(atk-1));
        }
    }
}

