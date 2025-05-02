#include "Pokemon.hpp"
#include <iostream>
#include <algorithm>

Pokemon::Pokemon(const std::string& nom, int pv, int degats)
  : nom_(nom), pv_(pv), degats_(degats) {}

void Pokemon::attaquer(Pokemon& cible) {
  std::cout << nom_ << " attaque " << cible.getNom()
            << " et inflige " << degats_ << " dégâts.\n";
  cible.recevoirDegats(degats_);
}

void Pokemon::recevoirDegats(int montant) {
  pv_ = std::max(0, pv_ - montant);
  std::cout << nom_ << " a maintenant " << pv_ << " PV.\n";
}

bool Pokemon::estKO() const {
  return pv_ <= 0;
}

const std::string& Pokemon::getNom() const { return nom_; }
int Pokemon::getPV() const            { return pv_; }

