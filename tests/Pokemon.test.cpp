#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Pokemon.hpp"

#include <vector>

TEST_CASE("PV initiaux et KO", "[Pokemon]") {
    std::vector<Type*>  types;    // pas de types pour ce test
    std::vector<Attack*> atks;    // pas d'attaques non plus

    Pokemon a("Pika", 50, types, atks);
    REQUIRE(a.getPV() == 50);
    REQUIRE_FALSE(a.estKO());
}

TEST_CASE("Réception de dégâts et KO", "[Pokemon]") {
    std::vector<Type*>  types;
    std::vector<Attack*> atks;

    Pokemon b("Bulbi", 40, types, atks);
    b.recevoirDegats(15);
    REQUIRE(b.getPV() == 25);
    REQUIRE_FALSE(b.estKO());

    b.recevoirDegats(30);
    REQUIRE(b.getPV() == 0);
    REQUIRE(b.estKO());  // on test bien 'b', pas 'a'
}

