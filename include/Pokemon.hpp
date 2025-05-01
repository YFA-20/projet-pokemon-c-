#pragma once
#include <string>
#include "Type.hpp"
#include "Attack.hpp"

class Pokemon {
public:
  Pokemon(const std::string& nom, int pv);
  void attaquer(Pokemon* cible, Attack* attaque);
  void recevoirDegats(int montant);
  bool estKO() const;

  // Accesseurs
  const std::string& getNom() const;
  int getPV() const;

private:
  std::string nom_;
  int pv_;
  std::vector<Type*> types_;
  std::vector<Attack*> attaques_;
};

