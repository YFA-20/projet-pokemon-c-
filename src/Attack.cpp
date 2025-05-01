#include "Attack.hpp"

Attack::Attack(const std::string& nom, int puissance, Type* type)
  : nom_(nom), puissance_(puissance), type_(type) {}

int Attack::getPuissance() const { return puissance_; }
Type* Attack::getType() const { return type_; }
const std::string& Attack::getNom() const { return nom_; }

