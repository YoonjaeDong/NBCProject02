#include "Magician.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Magician::Magician(string nickname)
    : Player(nickname)
{
    job_name = "마법사";
    cout << "* 마법사로 전직하였습니다." << endl;

    HP = 40;
    MP = 80;
    power = 35;
    defence = 15;
    accuracy = 60;
    speed = 60;
}

void Magician::attack(Monster* monster)
{
    int damage = power - monster->getDefence();

    if (damage <= 0)
        damage = 1;

    cout << "* " << monster->getName() << "에게 매직 미사일을 사용해"
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