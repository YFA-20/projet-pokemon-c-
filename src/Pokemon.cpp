#include "Pokemon.hpp"
#include <iostream>

Pokemon::Pokemon(const std::string& nom, int pv, int degats)
  : nom_(nom), pv_(pv), degats_(degats) {}

void Pokemon::attaquer(Pokemon& cible) {
  std::cout << nom_ << " attaque " << cible.getNom()
            << " et inflige " << degats_ << " dégâts.\n";
  int pvRestants = cible.getPV() - degats_;
  // on met les PV à zéro si on descend en dessous
  cible = Pokemon(cible.getNom(), std::max(0, pvRestants), cible.getPV()); 
  // ou mieux : ajouter une méthode recevoirDegats...  
}

bool Pokemon::estKO() const {
  return pv_ <= 0;
}

const std::string& Pokemon::getNom() const { return nom_; }
int Pokemon::getPV() const { return pv_; }
