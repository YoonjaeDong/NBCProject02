#include "Thief.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Thief::Thief(string nickname)
    : Player(nickname)
{
    job_name = "도적";
    cout << "* 도적으로 전직하였습니다." << endl;


    HP = 60;
    MP = 40;
    power = 25;
    defence = 10;
    accuracy = 60;
    speed = 80;
}

void Thief::attack(Monster* monster)
{
    int damage = power - monster->getDefence();

    if (damage <= 0)
        damage = 1;

    cout << "* " << monster->getName() << "에게 표창을 던져"
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