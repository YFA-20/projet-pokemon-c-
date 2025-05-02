#include "Type.hpp"
#include <algorithm>

Type::Type(const std::string& nom) : nom_(nom) {}

const std::string& Type::getNom() const { return nom_; }

void Type::addFaiblesse(Type* t) { faiblesses_.push_back(t); }
void Type::addResistance(Type* t) { resistances_.push_back(t); }

double Type::multiplicateurContre(Type* cible) const {
  if (std::find(faiblesses_.begin(), faiblesses_.end(), cible) != faiblesses_.end())
    return 2.0;
  if (std::find(resistances_.begin(), resistances_.end(), cible) != resistances_.end())
    return 0.5;
  return 1.0;
}

