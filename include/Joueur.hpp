#pragma once
#include "Dresseur.hpp"
#include <iostream>

/// Dresseur humain : affiche un menu et lit la réponse au clavier
class Joueur : public Dresseur {
public:
  Joueur(const std::string& nom,
         const std::vector<Pokemon*>& equipe)
    : Dresseur(nom, equipe) {}

  Action choisirAction() override {
    std::cout << "\n" << getNom() << ", à toi de jouer !\n";
    std::cout << "1) Attaquer\n2) Changer de Pokémon\nChoix> ";
    int choix; std::cin >> choix;

    if (choix == 2 && aPokemonDisponible()) {
      // lister les Pokémon dispo
      auto& team = equipe_;
      for (size_t i = 0; i < team.size(); ++i) {
        std::cout << i+1 << ") " << team[i]->getNom()
                  << " (" << team[i]->getPV() << " PV)\n";
      }
      std::cout << "Pokémon> ";
      int idx; std::cin >> idx;
      return Action::makeChangement(team.at(idx-1));
    }
    else {
      // lister les attaques
      auto* actif = getActif();
      size_t n = actif->getNbAttaques();
      for (size_t i = 0; i < n; ++i) {
        std::cout << i+1 << ") " << actif->getAttaque(i)->getNom() << "\n";
      }
      std::cout << "Attaque> ";
      int atk; std::cin >> atk;
      return Action::makeAttaque(actif->getAttaque(atk-1));
    }
  }
};

