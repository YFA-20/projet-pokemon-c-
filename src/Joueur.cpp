#include "Joueur.hpp"
#include <iostream>
#include <limits>

Joueur::Joueur(const std::string& nom,
               const std::vector<Pokemon*>& equipe)
  : Dresseur(nom, equipe)
{}

Action Joueur::choisirAction() {
    // 1) Menu principal
    std::cout << "\n" << getNom() << ", à toi de jouer !\n"
              << "1) Attaquer\n";
    if (equipe_.size() > 1)
        std::cout << "2) Changer de Pokémon\n";
    std::cout << "Choix> " << std::flush;

    int choix;
    if (!(std::cin >> choix)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choix = 1;
    }

    // 2) Si switch et plusieurs pokémons
    if (choix == 2 && aPokemonDisponible()) {
        std::cout << "Sélectionne le Pokémon :\n";
        for (size_t i = 0; i < equipe_.size(); ++i) {
            std::cout << (i+1) << ") "
                      << equipe_[i]->getNom()
                      << " (" << equipe_[i]->getPV() << " PV)\n";
        }
        std::cout << "Pokémon> " << std::flush;

        int idx;
        if (!(std::cin >> idx) || idx < 1 
            || idx > static_cast<int>(equipe_.size())) {
            idx = 1;
        }
        return Action::makeChangement(equipe_.at(idx-1));
    }

    // 3) Sinon attaque
    Pokemon* actif = getActif();
    size_t n = actif->getNbAttaques();
    std::cout << "Sélectionne l'attaque :\n";
    for (size_t i = 0; i < n; ++i) {
        std::cout << (i+1) << ") "
                  << actif->getAttaque(i)->getNom() << "\n";
    }
    std::cout << "Attaque> " << std::flush;

    int atk;
    if (!(std::cin >> atk) || atk < 1 || atk > static_cast<int>(n)) {
        atk = 1;
    }
    return Action::makeAttaque(actif->getAttaque(atk-1));
}

