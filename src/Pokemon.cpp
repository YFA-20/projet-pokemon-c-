#include "Pokemon.hpp"
#include <iostream>
#include <algorithm>

Pokemon::Pokemon(const std::string& nom,
                 int pv,
                 const std::vector<Type*>& types,
                 const std::vector<Attack*>& attaques)
  : nom_(nom), pv_(pv), types_(types), attaques_(attaques)
{
    // On suppose que types_.size() est 1 ou 2, attaques_.size() entre 1 et 4
}

void Pokemon::attaquer(Pokemon& cible) {
    // Prendre la première attaque
    Attack* atk = attaques_.front();

    // Calculer le multiplicateur pour chaque type de la cible
    double mult = 1.0;
    for (Type* t : cible.types_) {
        mult *= atk->getType()->multiplicateurContre(t);
    }

    int degats = static_cast<int>(atk->getPuissance() * mult);
    std::cout << nom_ << " utilise " << atk->getNom()
              << " et inflige " << degats
              << " dégâts sur " << cible.getNom() << ".\n";

    cible.recevoirDegats(degats);
}

void Pokemon::recevoirDegats(int montant) {
    pv_ = std::max(0, pv_ - montant);
    std::cout << nom_ << " a maintenant " << pv_ << " PV.\n";
}

bool Pokemon::estKO() const {
    return pv_ <= 0;
}

const std::string& Pokemon::getNom() const {
    return nom_;
}

int Pokemon::getPV() const {
    return pv_;
}

size_t Pokemon::getNbAttaques() const {
    return attaques_.size();
}

Attack* Pokemon::getAttaque(size_t index) const {
    return attaques_.at(index);
}

