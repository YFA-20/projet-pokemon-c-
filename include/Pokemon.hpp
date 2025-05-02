#pragma once

#include <string>
#include <vector>
#include "Type.hpp"
#include "Attack.hpp"

/// Classe de base représentant un Pokémon avec un ou deux types et plusieurs attaques
class Pokemon {
public:
  /// Constructeur :
  /// @param nom        : nom du Pokémon
  /// @param pv         : points de vie initiaux
  /// @param types      : liste de 1 à 2 types
  /// @param attaques   : liste de 1 à 4 attaques
  Pokemon(const std::string& nom,
          int pv,
          const std::vector<Type*>& types,
          const std::vector<Attack*>& attaques);

  /// Lance la 1ʳᵉ attaque disponible sur la cible
  void attaquer(Pokemon& cible);

  /// Soustrait @montant des PV (jamais négatif)
  void recevoirDegats(int montant);

  /// @return true si PV <= 0
  bool estKO() const;

  /// Accesseurs
  const std::string& getNom() const;
  int                 getPV()  const;

private:
  std::string            nom_;
  int                    pv_;
  std::vector<Type*>     types_;     // 1..2
  std::vector<Attack*>   attaques_;  // 1..4
};

