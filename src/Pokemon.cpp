#include "Pokemon.hpp"
#include <algorithm>
#include <iostream>

Pokemon::Pokemon(const std::string& nom, int pv)
  : nom_(nom), pv_(pv) {}

void Pokemon::attaquer(Pokemon* cible, Attack* attaque) {
  double mult = 1.0;
  for (auto t : cible->types_) {
    mult *= attaque->getType()->multiplicateurContre(t);
  }
  int degats = static_cast<int>(attaque->getPuissance() * mult);
  cible->recevoirDegats(degats);
  std::cout << nom_ << " utilise " << attaque->getNom()
            << " et inflige " << degats << " dégâts.\n";
}

void Pokemon::recevoirDegats(int montant) {
  pv_ = std::max(0, pv_ - montant);
  std::cout << nom_ << " perd " << montant << " PV (reste " << pv_ << ").\n";
}

bool Pokemon::estKO() const { return pv_ == 0; }

const std::string& Pokemon::getNom() const { return nom_; }
int Pokemon::getPV() const { return pv_; }

