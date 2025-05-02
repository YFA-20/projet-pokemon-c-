#pragma once

#include <string>
#include <vector>
#include "Type.hpp"
#include "Attack.hpp"

/// Représente un Pokémon avec types et attaques
class Pokemon {
public:
  /// Constructeur : nom, PV initiaux, 1..2 types et 1..4 attaques
  Pokemon(const std::string& nom,
          int pv,
          const std::vector<Type*>& types,
          const std::vector<Attack*>& attaques);

  /// Lancer la 1ʳᵉ attaque contre la cible
  void attaquer(Pokemon& cible);

  /// Réduire les PV et afficher le résultat
  void recevoirDegats(int montant);

  /// @return true si PV <= 0
  bool estKO() const;

  /// Accesseurs
  const std::string& getNom() const;
  int                 getPV()  const;

  /// @return nombre d’attaques disponibles
  size_t getNbAttaques() const;

  /// @return pointeur vers l’attaque à l’index (lance std::out_of_range si invalide)
  Attack* getAttaque(size_t index) const;

private:
  std::string            nom_;
  int                    pv_;
  std::vector<Type*>     types_;    // 1..2
  std::vector<Attack*>   attaques_; // 1..4
};

