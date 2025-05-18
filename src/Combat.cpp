#include "Combat.hpp"
#include <iostream>

void Combat::demarrer() {
    std::cout << "Début du combat : "
              << d1_->getNom() << " vs " << d2_->getNom() << " !\n";
    while (!estTermine()) {
        tourSuivant();
    }
    Dresseur* gagnant = d1_->aPokemonDisponible() ? d1_ : d2_;
    std::cout << "Victoire de " << gagnant->getNom() << " !\n";
}

void Combat::tourSuivant() {
    // 1) d1 joue
    Action a1 = d1_->choisirAction();
    if (a1.estAttaque()) {
        d1_->getActif()->attaquer(*d2_->getActif());
    } else {
        d1_->changerPokemon(a1.pokemonSuivant());
    }
    if (estTermine()) return;

    // 2) d2 joue
    Action a2 = d2_->choisirAction();
    if (a2.estAttaque()) {
        d2_->getActif()->attaquer(*d1_->getActif());
    } else {
        d2_->changerPokemon(a2.pokemonSuivant());
    }
}

