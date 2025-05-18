#pragma once

/// Interface pour toute entité avec laquelle on peut interagir
class Interagir {
public:
    virtual ~Interagir() = default;
    virtual void interagir() = 0;
};


