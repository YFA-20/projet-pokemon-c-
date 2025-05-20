#pragma once
#include "Dresseur.hpp"
#include <string>

/// Un leader de gym basique : Machine qui choisit toujours la 1ʳᵉ attaque
class LeaderGym : public Dresseur {
public:
    LeaderGym(const std::string& nom,
              const std::vector<Pokemon*>& equipe,
              int gymId,
              const std::string& badgeName);

    Action choisirAction() override;

    int getGymId()    const { return gymId_; }
    const std::string& getBadgeName() const { return badgeName_; }

private:
    int         gymId_;
    std::string badgeName_;
};

