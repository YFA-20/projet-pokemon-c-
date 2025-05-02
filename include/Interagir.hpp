#pragma once
#include "Action.hpp"

/// Interface pour toute entité capable de choisir une Action
class Interagir {
public:
  virtual ~Interagir() = default;
  virtual Action choisirAction() = 0;
};

