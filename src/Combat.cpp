#include "Combat.hpp"
#include <iostream>

Combat::Combat(Dresseur* d1, Dresseur* d2)
    : d1_(d1), d2_(d2), tour_(0)
{}

bool Combat::estTermine() const {
    return !d1_->aPokemonDisponible() || !d2_->aPokemonDisponible();
}

void Combat::tourSuivant() {
    ++tour_;
    std::cout << "\n--- Tour " << tour_ << " ---\n";

    // Chaque dresseur choisit son action
    Action a1 = d1_->choisirAction();
    Action a2 = d2_->choisirAction();

    // Récupération des Pokémons actifs
    Pokemon* p1 = d1_->getActif();
    Pokemon* p2 = d2_->getActif();

    // Exécution de la première action
    if (a1.estAttaque()) {
        p1->attaquer(*p2);
    } else {
        int idx = d1_->indexActif(a1.nouveauPokemon);
        d1_->changerPokemon(idx);
    }

    // Si le combat est fini après la première action, on stoppe
    if (estTermine()) return;

    // Exécution de la seconde action
    if (a2.estAttaque()) {
        p2->attaquer(*p1);
    } else {
        int idx = d2_->indexActif(a2.nouveauPokemon);
        d2_->changerPokemon(idx);
    }
}

void Combat::demarrer() {
    std::cout << "Début du combat entre "
              << d1_->getNom() << " et " << d2_->getNom() << " !\n";
    while (!estTermine()) {
        tourSuivant();
    }
    std::cout << "\nFin du combat.\n";
}

