#pragma once

#include "Dresseur.hpp"

/// Gère un combat entre deux Dresseurs.
class Combat {
public:
    /// @param d1 : premier dresseur
    /// @param d2 : second dresseur
    Combat(Dresseur* d1, Dresseur* d2);

    /// Démarre la boucle de combat jusqu’à la défaite d’un des deux.
    void demarrer();

    /// Exécute un seul tour de combat.
    void tourSuivant();

    /// @return true si l’un des deux n’a plus de Pokémon disponible.
    bool estTermine() const;

private:
    Dresseur* d1_;
    Dresseur* d2_;
    int       tour_;
};

