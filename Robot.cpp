//
// Created by CMYHJ on 2024/1/31.
//
#include "Robot.h"

using namespace std;

Robot::Robot(int time, int team, int number, int type) {
    LastCommandTime=time;
    Team = team;
    Number = number;
    Type = type;
}

void Robot::HotDamageAndSet(int time) {
        if (!isDead ) {//找到对应机器人
            int HotGap = Hot - Hot_Max;
            int TimeGap = time - LastCommandTime;
            if (HotGap > TimeGap) {//热量未减完
                HP -= (HotGap * 2 - TimeGap + 1) * TimeGap / 2;
                Hot -= TimeGap;
            } else {//热量减完
                HP -= HotGap * (HotGap + 1) / 2;
                Hot = 0;
            }
        }
    }

void Robot::TimeSet(int time) {
    LastCommandTime=time;
}

void Robot::TellIsDead() {
    if (HP <= 0) {//似了
        isDead = true;
        std::cout<<"D "<<Team<<" "<<Number<<std::endl;
        std::cout<<"HP:"<<HP<<std::endl;//<<""<<Number<<std::endl;
    }
}

