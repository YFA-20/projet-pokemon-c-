#pragma once

#include <vector>
#include "Dresseur.hpp"

/// Dresseur humain qui affiche un menu et lit la réponse au clavier
class Joueur : public Dresseur {
public:
    Joueur(const std::string& nom,
           const std::vector<Pokemon*>& equipe);

    /// Affiche le menu et renvoie l’action choisie
    Action choisirAction() override;
};

