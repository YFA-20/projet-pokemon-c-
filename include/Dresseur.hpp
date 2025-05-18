#pragma once

#include <string>
#include <vector>
#include "Interagir.hpp"  // pour hériter
#include "Action.hpp"
class Pokemon;           // forward declare

/// Classe de base pour tous les dresseurs (joueur, leader, maître)
class Dresseur : public Interagir {
public:
    /// Constructeur : nom et équipe initiale
    Dresseur(const std::string& nom,
             const std::vector<Pokemon*>& equipe);

    virtual ~Dresseur();

    /// @return action choisie (pure virtual)
    virtual Action choisirAction() = 0;

    /// Getters
    const std::string& getNom() const;
    Pokemon*           getActif() const;

    /// @return true s’il reste un Pokémon non-KO
    bool aPokemonDisponible() const;

    /// Change de Pokémon actif si possible
    void changerPokemon(Pokemon* nouveau);

    /// Interaction simple (par défaut)
    void interagir() override;

protected:
    std::string            nom_;
    std::vector<Pokemon*>  equipe_;
    Pokemon*               actif_;
};

