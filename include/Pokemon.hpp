#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Interagir.hpp"  
#include "Type.hpp"
#include "Attack.hpp"

/// Représente un Pokémon avec types, attaques et interaction
class Pokemon : public Interagir {
public:
    /// @param nom     nom du Pokémon
    /// @param pv      points de vie initiaux
    /// @param types   vecteur de 1 ou 2 Type*
    /// @param attaques vecteur de 1 à 4 Attack*
    Pokemon(const std::string& nom,
            int pv,
            const std::vector<Type*>& types,
            const std::vector<Attack*>& attaques);

    /// attaque simple avec l’attaque*(lance les dégâts)
    void attaquer(Pokemon& cible);

    /// nouvelle surcharge : attaque avec choix d’Attack*
    void attaquer(Pokemon& cible, Attack* atk);

    void recevoirDegats(int montant);
    bool estKO() const;

    // Accesseurs
    const std::string& getNom() const;
    int                getPV()  const;
    size_t             getNbAttaques() const;
    Attack*            getAttaque(size_t idx) const;

    /// Interaction : Pokémon réagit quand on lui parle
    void interagir() override {
        std::cout << getNom()
                  << " te regarde et fronce les sourcils curieusement.\n";
    }

    // Getters utiles pour le menu
    const std::vector<Type*>&   getTypes()    const { return types_; }
    const std::vector<Attack*>& getAttaques() const { return attaques_; }

private:
    std::string            nom_;
    int                    pv_;
    std::vector<Type*>     types_;
    std::vector<Attack*>   attaques_;
};

