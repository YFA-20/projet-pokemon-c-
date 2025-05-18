#include <iostream>
#include <Combat.hpp>
#include "Joueur.hpp"
#include "Pokemon.hpp"
#include "Action.hpp"


Combat::Combat(Dresseur* d1, Dresseur* d2)
  : d1_(d1), d2_(d2), tour_(1)
{}

bool Combat::estTermine() const {
    return !d1_->aPokemonDisponible() || !d2_->aPokemonDisponible();
}

void Combat::tourSuivant() {
    Action a1 = d1_->choisirAction();
    if (a1.estAttaque()) {
        d1_->getActif()->attaquer(*d2_->getActif(), a1.attaqueChoisie());
    } else {
        d1_->changerPokemon(a1.pokemonSuivant());
    }
    if (estTermine()) return;

    Action a2 = d2_->choisirAction();
    if (a2.estAttaque()) {
        d2_->getActif()->attaquer(*d1_->getActif(), a2.attaqueChoisie());
    } else {
        d2_->changerPokemon(a2.pokemonSuivant());
    }

    ++tour_;
}

void Combat::demarrer() {
    std::cout << "\nDébut du combat entre "
              << d1_->getNom() << " et " << d2_->getNom() << " !\n";

    while (!estTermine()) {
        std::cout << "\n--- Tour " << tour_ << " ---\n";
        tourSuivant();
    }

    Dresseur* gagnant = d1_->aPokemonDisponible() ? d1_ : d2_;
    Dresseur* perdant  = (gagnant == d1_) ? d2_ : d1_;

    std::cout << "\nFin du combat. Vainqueur : "
              << gagnant->getNom() << " !\n";

    if (auto* j = dynamic_cast<Joueur*>(gagnant)) {
        j->addDefeatedTrainer(perdant);
    }
}

