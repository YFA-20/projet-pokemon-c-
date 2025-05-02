#pragma once

#include <string>

class Pokemon {
public:
  // Constructeur à 3 paramètres : nom, PV initiaux et dégâts fixes
  Pokemon(const std::string& nom, int pv, int degats);

  // Attaque une autre instance de Pokémon
  void attaquer(Pokemon& cible);

  // Gère la réception des dégâts
  void recevoirDegats(int montant);
  bool estKO() const;

  // Accesseurs
  const std::string& getNom() const;
  int                 getPV()  const;

private:
  std::string nom_;
  int         pv_;
  int         degats_;
};

