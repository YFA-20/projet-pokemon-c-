# Simulateur Pokémon en C++

Bienvenue dans le projet **simulateur Pokémon** développé en C++. Ce programme permet de simuler des combats entre un joueur humain et des dresseurs contrôlés par l’ordinateur dans des gymnases Pokémon, à la manière des jeux classiques de la franchise.

## Sommaire

- [Fonctionnalités](#fonctionnalités)
- [Structure du projet](#structure-du-projet)
- [Diagrammes UML](#diagrammes-uml)
- [Chargement des données](#chargement-des-données)
- [Instructions de compilation](#instructions-de-compilation)
- [Exécution du simulateur](#exécution-du-simulateur)
- [Auteurs](#auteurs)

---

## Fonctionnalités

- Combat tour par tour entre un **joueur humain** et un **Leader de Gym**.
- Choix d'action : attaquer, changer de Pokémon, consulter les statistiques.
- Gestion d'équipe Pokémon (ordre, PV restants, Pokémon KO).
- **Interface d'interaction** pour interagir avec Pokémon KO ou dresseurs vaincus.
- Attribution automatique de **badges** après victoire contre un gymnase.
- Accès à un menu hors-combat si un gymnase a déjà été battu.
- Statistiques persistantes durant toute la session (badges, victoires, défaites).
- Chargement dynamique des entités depuis des **fichiers CSV**.

---

## Structure du projet

Voici les principales classes du projet :

### Cœur du métier

- `Pokemon` : entité de base avec PV, types et attaques.
- `Attack` : encapsule le nom, la puissance et le type d'une attaque.
- `Type` : contient les relations de résistance/faiblesse.
- `Action` : classe utilitaire représentant une attaque ou un changement de Pokémon.

### Contrôle de la simulation

- `Dresseur` *(classe abstraite)* : représente un dresseur avec une équipe de Pokémon.
  - `Joueur` : dérivé contrôlé par l'humain.
  - `LeaderGym` : leader de gymnase avec un badge.
  - `MaitrePokemon` : dresseur spécial accessible après tous les badges.
- `Combat` : moteur qui exécute les tours jusqu’à la victoire de l’un des deux dresseurs.
- `MenuPrincipal` : boucle principale permettant de choisir les gymnases et gérer les combats.

### Chargement des données

- `DataLoader` : lecture des fichiers CSV et création des entités correspondantes (`Pokemon`, `Joueur`, `LeaderGym`, `MaitrePokemon`).

---

## Diagrammes UML

Trois diagrammes UML sont disponibles dans le dossier `/diagrams` :

1. **Coeur de métier** : `Pokemon`, `Attack`, `Type`, `Action`
2. **Contrôle du simulateur** : `Dresseur`, `Joueur`, `LeaderGym`, `Combat`, `MenuPrincipal`
3. **Chargement des données** : `DataLoader`, fichiers CSV

---

## Chargement des données

Les fichiers CSV permettent de configurer facilement :

- `pokemon.csv` : liste des Pokémon, types, PV, attaques
- `joueur.csv` : nom et équipe du joueur
- `leaders.csv` : leaders, badges, équipes
- `maitres.csv` : maîtres Pokémon (optionnel)

Ces fichiers sont lus au lancement via `DataLoader`.

---

## Instructions de compilation

Ce projet est compilé avec `g++`. Il suffit d’exécuter :

```bash
make

