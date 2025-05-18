#pragma once

#include "Joueur.hpp"
#include "LeaderGym.hpp"
#include "MaitrePokemon.hpp"
#include <vector>

/// Affiche le menu principal et lance les combats.
/// @param joueur  Pointeur sur le joueur
/// @param leaders Liste des leaders de gymnase
/// @param masters Liste des maîtres Pokémon
void lancerMenuPrincipal(Joueur* joueur,
                         const std::vector<LeaderGym*>& leaders,
                         const std::vector<MaitrePokemon*>& masters);
