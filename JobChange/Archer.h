#pragma once
#include "Player.h"

class Monster;

class Archer : public Player {
public:
    Archer(string nickname);
    void attack(Monster* monster) override;
};
