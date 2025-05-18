#pragma once

// Forward declarations pour casser la circularité
class Pokemon;
class Attack;

/// Représente le choix d’un dresseur : attaque ou changement de Pokémon
class Action {
public:
    enum Kind { ATTAQUE, CHANGEMENT };

    // Fabriques
    static Action makeAttaque(Attack* a) {
        Action x;
        x.kind_            = ATTAQUE;
        x.attaqueChoisie_  = a;
        return x;
    }
    static Action makeChangement(Pokemon* p) {
        Action x;
        x.kind_           = CHANGEMENT;
        x.pokemonSuivant_ = p;
        return x;
    }

    // Query
    Kind    kind()           const { return kind_; }
    bool    estAttaque()     const { return kind_ == ATTAQUE; }
    bool    estChangement()  const { return kind_ == CHANGEMENT; }

    // Accesseurs
    Attack* attaqueChoisie() const { return attaqueChoisie_; }
    Pokemon* pokemonSuivant() const { return pokemonSuivant_; }

private:
    Kind      kind_;
    Attack*   attaqueChoisie_ = nullptr;
    Pokemon*  pokemonSuivant_ = nullptr;
};

