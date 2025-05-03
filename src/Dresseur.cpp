#include "Dresseur.hpp"
#include <iostream>

Dresseur::Dresseur(const std::string& nom,
                   const std::vector<Pokemon*>& equipe)
    : nom_(nom), equipe_(equipe), actif_(equipe.front())
{}

const std::string& Dresseur::getNom() const {
    return nom_;
}

Pokemon* Dresseur::getActif() const {
    return actif_;
}

int Dresseur::indexActif(Pokemon* p) const {
    for (int i = 0; i < static_cast<int>(equipe_.size()); ++i) {
        if (equipe_[i] == p) return i;
    }
    return -1;
}

bool Dresseur::aPokemonDisponible() const {
    for (auto* p : equipe_) {
        if (!p->estKO()) return true;
    }
    return false;
}

void Dresseur::changerPokemon(int idx) {
    if (idx >= 0 && idx < static_cast<int>(equipe_.size())
        && !equipe_[idx]->estKO())
    {
        actif_ = equipe_[idx];
        std::cout << nom_ << " change pour "
                  << actif_->getNom() << ".\n";
    }
}

Action Dresseur::choisirAction() {
    // Si le Pokémon actif est KO, on switch vers le premier disponible
    if (actif_->estKO()) {
        for (auto* p : equipe_) {
            if (!p->estKO()) {
                return Action::makeChangement(p);
            }
        }
    }
    // Sinon, on attaque avec la première attaque du Pokémon actif
    return Action::makeAttaque(actif_->getAttaque(0));
}

