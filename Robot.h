//
// Created by CMYHJ on 2024/1/31.
//

#ifndef SHIJUE_HOMEWORK_ROBOT_H
#define SHIJUE_HOMEWORK_ROBOT_H
#include <iostream>


using namespace std;

class Robot
{
public:
    int Type;
    int Grade=1;
    int Team;
    int Number;
    int HP_Max;
    int Hot_Max=0;
    int HP;
    int Hot=0;
    bool Dead = false;

    Robot(int team,int number,int type);
};


#endif //SHIJUE_HOMEWORK_ROBOT_H
