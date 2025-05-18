#pragma once

#include "Dresseur.hpp"

class Combat {
public:
    Combat(Dresseur* d1, Dresseur* d2);
    void demarrer();
    void tourSuivant();
    bool estTermine() const;

private:
    Dresseur* d1_;
    Dresseur* d2_;
    int       tour_;
};

