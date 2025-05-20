#pragma once

#include <string>
#include <vector>
#include "Dresseur.hpp"

/// Un Maître Pokémon : Machine basique, bonus de dégâts (25 %) à gérer plus tard
class MaitrePokemon : public Dresseur {
public:
  /// nom, équipe de 1..6 Pokémon
  MaitrePokemon(const std::string& nom,
                const std::vector<Pokemon*>& equipe);

  /// Machine : choisit toujours la première attaque
  Action choisirAction() override;
};

