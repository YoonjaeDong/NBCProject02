#include "Archer.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Archer::Archer(string nickname)
    : Player(nickname)
{
    job_name = "궁수";
    cout << "* 궁수로 전직하였습니다." << endl;

    HP = 60;
    MP = 40;
    power = 30;
    defence = 15;
    accuracy = 80;
    speed = 60;
  
}

void Archer::attack(Monster* monster)
{
    int damage = power - monster->getDefence();

    if (damage <= 0)
        damage = 1;

    cout << "* " << monster->getName() << "에게 활을 쏴"
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