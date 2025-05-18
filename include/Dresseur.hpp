#pragma once

#include <string>
#include <vector>
#include "Interagir.hpp"
#include "Action.hpp"
#include "Pokemon.hpp"

/// Classe de base pour tout Dresseur (Joueur, LeaderGym, MaîtrePokemon)
class Dresseur : public Interagir {
public:
    Dresseur(const std::string& nom,
             const std::vector<Pokemon*>& equipe);
    virtual ~Dresseur();

    /// Implémenté par chaque sous-classe
    virtual Action choisirAction() = 0;

    // Accesseurs
    const std::string&            getNom()  const;
    Pokemon*                      getActif() const;
    bool                          aPokemonDisponible() const;
    void                          changerPokemon(Pokemon* nouveau);

    /// Permet de lire l’équipe (pour main.cpp, etc.)
    const std::vector<Pokemon*>&  getEquipe() const { return equipe_; }

    /// Interaction publique (encouragement)
    void                          interagir() override;

protected:
    // Notre équipe, accessible aux classes dérivées
    std::vector<Pokemon*>         equipe_;

private:
    std::string                   nom_;
    Pokemon*                      pokemonActif_;
};

