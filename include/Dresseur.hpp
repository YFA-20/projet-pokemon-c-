#pragma once

#include <string>
#include <vector>
#include "Pokemon.hpp"
#include "Interagir.hpp"

/// Un dresseur possède un nom, une équipe de Pokémons et choisit des actions.
class Dresseur : public Interagir {
public:
    /// Constructeur
    /// @param nom    : nom du dresseur
    /// @param equipe : liste de 1..6 Pokémons
    Dresseur(const std::string& nom,
             const std::vector<Pokemon*>& equipe);

    /// @return le nom du dresseur
    const std::string& getNom() const;

    /// @return le Pokémon actif
    Pokemon* getActif() const;

    /// @return l’index de p dans l’équipe, ou -1 si non trouvé
    int indexActif(Pokemon* p) const;

    /// @return true s’il reste au moins un Pokémon non KO
    bool aPokemonDisponible() const;

    /// Change le Pokémon actif vers l’index idx (0..size-1)
    void changerPokemon(int idx);

    /// Choisit une action : attaque si possible, sinon switch
    Action choisirAction() override;

protected:
    std::vector<Pokemon*> equipe_;  // 1..6
    Pokemon*              actif_;   // toujours un des membres de equipe_

private:
    std::string nom_;
};

