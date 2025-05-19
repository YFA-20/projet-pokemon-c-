#pragma once

#include <vector>
#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"

/// Affiche le menu principal et lance les combats.
/// @param joueur   Pointeur sur le joueur
/// @param leaders  Liste des leaders de gymnase
/// @param masters  Liste des maîtres Pokémon (non utilisés ici)
void lancerMenuPrincipal(Joueur* joueur,
                         const std::vector<LeaderGym*>& leaders,
                         const std::vector<MaitrePokemon*>& masters);

