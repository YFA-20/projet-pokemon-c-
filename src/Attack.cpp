#include "Attack.hpp"
#include "Type.hpp"

Attack::Attack(const std::string& nom, int puissance, Type* type)
  : nom_(nom), puissance_(puissance), type_(type) {}

const std::string& Attack::getNom() const       { return nom_; }
int                Attack::getPuissance() const { return puissance_; }
Type*              Attack::getType() const      { return type_; }

