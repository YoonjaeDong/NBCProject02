#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

Monster::Monster(string name)
    : name(name), HP(10), power(30), defence(10), speed(10)
{
}

void Monster::attack(Player* player)
{
    int damage = power - player->getDefence();
    if (damage <= 0) damage = 1;

    cout << "* " << name << "이(가) " << player->getNickname()
        << "에게 " << damage << "의 데미지를 주었다!" << endl;

    int newHP = player->getHP() - damage;
    player->setHP(newHP);

    if (player->getHP() > 0) {
        cout << "* " << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
    }
    else {
        cout << "* " << player->getNickname() << "이(가) 쓰러졌다..." << endl;
    }
}

string Monster::getName() { return name; }
int Monster::getHP() { return HP; }
int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }
int Monster::getSpeed() { return speed; }

void Monster::setName(string name) { this->name = name; }
void Monster::setHP(int HP) { this->HP = HP; }
void Monster::setPower(int power) { this->power = power; }
void Monster::setDefence(int defence) { this->defence = defence; }
void Monster::setSpeed(int speed) { this->speed = speed; }
