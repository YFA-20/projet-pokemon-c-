#include "Dresseur.hpp"
#include "Pokemon.hpp"   // pour la méthode estKO()
#include <algorithm>     // std::find_if

Dresseur::Dresseur(const std::string& nom,
                   const std::vector<Pokemon*>& equipe)
  : nom_(nom),
    equipe_(equipe),
    actif_(equipe.empty() ? nullptr : equipe.front())
{}

Dresseur::~Dresseur() = default;

const std::string& Dresseur::getNom() const {
    return nom_;
}

Pokemon* Dresseur::getActif() const {
    return actif_;
}

bool Dresseur::aPokemonDisponible() const {
    for (auto* p : equipe_) {
        if (p && !p->estKO()) return true;
    }
    return false;
}

void Dresseur::changerPokemon(Pokemon* nouveau) {
    // on accepte le changement si le Pokémon fait partie de l'équipe et n'est pas KO
    auto it = std::find(equipe_.begin(), equipe_.end(), nouveau);
    if (it != equipe_.end() && !(*it)->estKO()) {
        actif_ = nouveau;
    }
}

void Dresseur::interagir() {
    // comportement par défaut
    std::cout << nom_ << " te fait un signe d'encouragement.\n";
}

