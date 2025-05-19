#include "Joueur.hpp"
#include "Pokemon.hpp"

#include <iostream>
#include <limits>
#include <algorithm>
#include <string>

Joueur::Joueur(const std::string& nom,
               const std::vector<Pokemon*>& equipe)
  : Dresseur(nom, equipe)
{}

Joueur::~Joueur() = default;

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
            afficherMesPokemons();
            continue;
        }

        // 2) Attaquer
        if (choix == 2) {
            auto* actif = getActif();
            size_t n = actif->getNbAttaques();
            std::cout << "\nSélectionne l'attaque :\n";
            for (size_t i = 0; i < n; ++i) {
                std::cout << " " << (i+1) << ") "
                          << actif->getAttaque(i)->getNom() << "\n";
            }
            std::cout << "Attaque> " << std::flush;
            int atk;
            if (!(std::cin >> atk) || atk < 1 || atk > int(n)) atk = 1;
            return Action::makeAttaque(actif->getAttaque(atk-1));
        }

        // 3) Changer de Pokémon
        if (choix == 3 && aPokemonDisponible()) {
            std::cout << "\nSélectionne le Pokémon :\n";
            const auto& eq = getEquipe();
            for (size_t i = 0; i < eq.size(); ++i) {
                std::cout << " " << (i+1) << ") "
                          << eq[i]->getNom()
                          << " (" << eq[i]->getPV() << " PV)\n";
            }
            std::cout << "Pokémon> " << std::flush;
            int idx;
            if (!(std::cin >> idx) || idx < 1 || idx > int(eq.size()))
                idx = 1;
            return Action::makeChangement(eq.at(idx-1));
        }

        // 4) Afficher PV de l’équipe
        if (choix == 4) {
            afficherPvEquipe();
            continue;
        }

        // 5) Réorganiser l’ordre des Pokémon
        if (choix == 5 && getEquipe().size() > 1) {
            std::cout << "\n=== Réorganisation de l’équipe ===\n";
            auto eq = getEquipe();  // copie simple pour lister
            for (size_t i = 0; i < eq.size(); ++i) {
                std::cout << " " << (i+1) << ") " << eq[i]->getNom() << "\n";
            }
            std::cout << "Déplacer quel Pokémon (numéro)? " << std::flush;
            int src, dst;
            std::cin >> src;
            std::cout << "Vers quelle position (1–" << eq.size() << ")? " << std::flush;
            std::cin >> dst;
            src = std::clamp(src, 1, int(eq.size()));
            dst = std::clamp(dst, 1, int(eq.size()));
            // on modifie l'ordre interne
            auto tmp = getEquipe()[src-1];
            auto& e = const_cast<std::vector<Pokemon*>&>(getEquipe());
            e.erase(e.begin() + (src-1));
            e.insert(e.begin() + (dst-1), tmp);
            std::cout << "Équipe mise à jour !\n";
            continue;
        }

        // 6) Afficher mes statistiques
        if (choix == 6) {
            afficherStatistiques();
            continue;
        }

        // 7) Interagir avec KO/vaincus
        if (choix == 7) {
            interagirKOvaincus();
            continue;
        }

        // Par défaut (saisie hors-1..7), on retombe sur l’attaque
    }
}

// ─── Hors-combat : affichages ─────────────────────────────────────

void Joueur::afficherMesPokemons() const {
    std::cout << "\n=== Mon Équipe Pokémon ===\n";
    const auto& eq = getEquipe();
    for (size_t i = 0; i < eq.size(); ++i) {
        auto* p = eq[i];
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
}

void Joueur::afficherPvEquipe() const {
    std::cout << "\n=== PV restants de l’équipe ===\n";
    const auto& eq = getEquipe();
    for (size_t i = 0; i < eq.size(); ++i) {
        auto* p = eq[i];
        std::cout << " " << (i+1) << ") "
                  << p->getNom()
                  << " : " << p->getPV() << " PV\n";
    }
    std::cout << "===============================\n";
}

void Joueur::afficherStatistiques() const {
    std::cout << "\n=== Mes statistiques ===\n"
              << " Badges    : " << getNbBadges()    << "\n"
              << " Victoires : " << getNbVictoires() << "\n"
              << " Défaites  : " << getNbDefaites()  << "\n"
              << "=======================\n";
}

void Joueur::interagirKOvaincus() const {
    std::cout << "\n=== Pokémon KO ===\n";
    for (auto* p : getEquipe())
        if (p->estKO())
            std::cout << " - " << p->getNom() << "\n";

    std::cout << "\n=== Entraîneurs vaincus ===\n";
    for (auto* d : getDefeatedTrainers())
        std::cout << " - " << d->getNom() << "\n";
}

