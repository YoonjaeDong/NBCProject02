#include "Warrior.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Warrior::Warrior(string nickname)
    : Player(nickname)         
{
    job_name = "전사";
    cout << "* 전사로 전직하였습니다." << endl;

    HP = 80;
    MP = 40;
    power = 40;
    defence = 20;
    accuracy = 60;
    speed = 40;
}

void Warrior::attack(Monster* monster)
{
    int damage = power - monster->getDefence();

    if (damage <= 0)
        damage = 1;

    cout << "* " << monster->getName() << "에게 검을 휘둘러"
        << damage << "의 데미지를 주었다!" << endl;

    monster->setHP(monster->getHP() - damage);

    if (monster->getHP() > 0) {
        cout << monster->getName() << "의 남은 HP: "
            << monster->getHP() << endl;
    }
    else {
        cout << "플레이어가 승리했습니다!" << endl;
    }
}