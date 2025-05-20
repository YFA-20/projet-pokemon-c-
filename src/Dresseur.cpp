#include "Dresseur.hpp"
#include <algorithm>   
#include <iostream>    

Dresseur::Dresseur(const std::string& nom,
                   const std::vector<Pokemon*>& equipe)
  : nom_(nom),
    equipe_(equipe),
    pokemonActif_(equipe.empty() ? nullptr : equipe.front())
{}

Dresseur::~Dresseur() = default;

const std::string& Dresseur::getNom() const {
    return nom_;
}

Pokemon* Dresseur::getActif() const {
    return pokemonActif_;
}

bool Dresseur::aPokemonDisponible() const {
    for (auto* p : equipe_) {
        if (!p->estKO()) {
            return true;
        }
    }
    return false;
}

void Dresseur::changerPokemon(Pokemon* nouveau) {
    auto it = std::find(equipe_.begin(), equipe_.end(), nouveau);
    if (it != equipe_.end() && !(*it)->estKO()) {
        pokemonActif_ = nouveau;
    }
}

void Dresseur::interagir() {
    std::cout << getNom()
              << " te fait un signe d'encouragement.\n";
}

