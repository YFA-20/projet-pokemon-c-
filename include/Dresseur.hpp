#pragma once
#include <string>
#include <vector>
#include "Pokemon.hpp"
#include "Interagir.hpp"

/// Un dresseur a un nom, une équipe de 1..6 Pokémon et un Pokémon actif
class Dresseur : public Interagir {
public:
  Dresseur(const std::string& nom,
           const std::vector<Pokemon*>& equipe);

  // Accesseurs
  const std::string& getNom() const;

  // Implémente Interagir
  Action choisirAction() override;

  // Permet de switcher manuellement (appelé par un menu ultérieurement)
  void changerPokemon(int idx);

  bool aPokemonDisponible() const;

protected:
  std::vector<Pokemon*> equipe_;  // 1..6
  Pokemon*              actif_;   // toujours un des membres de equipe_

private:
  std::string nom_;
};

