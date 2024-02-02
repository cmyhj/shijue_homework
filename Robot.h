//
// Created by CMYHJ on 2024/1/31.
//

#ifndef SHIJUE_HOMEWORK_ROBOT_H
#define SHIJUE_HOMEWORK_ROBOT_H

#include <iostream>


using namespace std;

class Robot {
public:
    int Type;
    int Level = 1;
    int Team;
    int Number;
    int HP_Max;
    int Hot_Max = 0;
    int HP;
    int Hot = 0;
    int LastCommandTime=0;
    bool isDead= false;

    Robot(int time, int team, int number, int type);
    void HotDamageAndSet(int time);
    void TimeSet(int time);
    void TellIsDead();
};


#endif //SHIJUE_HOMEWORK_ROBOT_H
