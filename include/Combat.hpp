#pragma once

#include "Dresseur.hpp"

/// Boucle de combat entre deux dresseurs
class Combat {
public:
    Combat(Dresseur* d1, Dresseur* d2)
      : d1_(d1), d2_(d2)
    {}

    /// Lance la boucle jusqu’à ce qu’une équipe soit KO
    void demarrer();

private:
    void tourSuivant();
    bool estTermine() const {
        return !d1_->aPokemonDisponible() || !d2_->aPokemonDisponible();
    }

    Dresseur* d1_;
    Dresseur* d2_;
};

