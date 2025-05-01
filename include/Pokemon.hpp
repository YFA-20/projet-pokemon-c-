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
#pragma once
#include <string>

class Pokemon {
public:
  // constructeur : nom, points de vie initiaux, dégâts fixes
  Pokemon(const std::string& nom, int pv, int degats);

  // attaque une autre instance et lui enlève pv de dégâts
  void attaquer(Pokemon& cible);

  // indicateur KO
  bool estKO() const;

  // accesseurs
  const std::string& getNom() const;
  int getPV() const;

private:
  std::string nom_;
  int pv_;
  int degats_;
};

