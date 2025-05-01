#include "Pokemon.hpp"
#include <iostream>

Pokemon::Pokemon(const std::string& nom, int pv)
  : nom_(nom), pv_(pv) {}

void Pokemon::attaquer(Pokemon* cible) {
  // TODO : calculer et infliger les dégâts
  std::cout << nom_ << " attaque !\n";
  cible->recevoirDegats(10);  // exemple fixe
}

void Pokemon::recevoirDegats(int montant) {
  pv_ = std::max(0, pv_ - montant);
  std::cout << nom_ << " perd " << montant 
            << " PV (reste " << pv_ << ").\n";
}

bool Pokemon::estKO() const {
  return pv_ <= 0;
}

