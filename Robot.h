//
// Created by CMYHJ on 2024/1/31.
//

#ifndef SHIJUE_HOMEWORK_ROBOT_H
#define SHIJUE_HOMEWORK_ROBOT_H

#include <iostream>


using namespace std;

class Robot {
public:
    int type_;
    int level_ = 1;
    int team_;
    int number_;
    int HP_max_;
    int hot_max_ = 0;
    int HP_;
    int hot_ = 0;
    int last_command_time_ = 0;
    bool is_dead_ = false;

    Robot(int time, int team, int number, int type);

    void HotDamageAndSet(int time);

    void TimeSet(int time);

    void TellIsDead();
};


#endif //SHIJUE_HOMEWORK_ROBOT_H
