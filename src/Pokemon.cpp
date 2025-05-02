#include "Pokemon.hpp"
#include <iostream>
#include <algorithm>

Pokemon::Pokemon(const std::string& nom,
                 int pv,
                 const std::vector<Type*>& types,
                 const std::vector<Attack*>& attaques)
  : nom_(nom), pv_(pv), types_(types), attaques_(attaques)
{
  // On suppose que types.size() est 1 ou 2, attaques.size() entre 1 et 4
}

void Pokemon::attaquer(Pokemon& cible) {
  // On prend la première attaque de la liste
  Attack* atk = attaques_.front();

  // Calcul du multiplicateur selon tous les types de la cible
  double mult = 1.0;
  for (Type* t : cible.types_) {
    mult *= atk->getType()->multiplicateurContre(t);
  }

  // Dégâts effectifs
  int degats = static_cast<int>(atk->getPuissance() * mult);

  std::cout << nom_ << " utilise " << atk->getNom()
            << " et inflige " << degats << " dégâts sur "
            << cible.getNom() << ".\n";
  cible.recevoirDegats(degats);
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

