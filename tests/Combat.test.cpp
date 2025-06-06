#include "catch.hpp"
#include "Combat.hpp"
#include "Attack.hpp"
#include "Type.hpp"
#include "Pokemon.hpp"
#include "Dresseur.hpp"

class DummyTrainer : public Dresseur {
public:
    DummyTrainer(const std::string& nom,
                 const std::vector<Pokemon*>& equipe,
                 Attack* atk)
        : Dresseur(nom, equipe), atk_(atk) {}

    Action choisirAction() override {
        return Action::makeAttaque(atk_);
    }
private:
    Attack* atk_;
};

TEST_CASE("Combat utilise l'attaque choisie", "[Combat]") {
    Type normal("Normal");
    Attack griffe("Griffe", 10, &normal);
    Attack grosse("GrosseAttaque", 60, &normal);

    std::vector<Type*> types{&normal};
    std::vector<Attack*> atk1{&griffe, &grosse};
    Pokemon p1("P1", 50, types, atk1);

    std::vector<Attack*> atk2{&griffe};
    Pokemon p2("P2", 50, types, atk2);

    DummyTrainer t1("T1", {&p1}, &grosse);
    DummyTrainer t2("T2", {&p2}, &griffe);

    Combat combat(&t1, &t2);
    combat.demarrer();

    REQUIRE(p2.estKO());
    REQUIRE(p1.getPV() == 50); // P2 KO avant de riposter
}
