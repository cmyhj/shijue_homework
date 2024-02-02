//
// Created by CMYHJ on 2024/1/31.
//
#include "Robot.h"

using namespace std;

Robot::Robot(int time, int team, int number, int type) {
    LastCommandTime = time;
    Team = team;
    Number = number;
    Type = type;
}

void Robot::HotDamageAndSet(int time) {
    if (!isDead) {//找到对应机器人
        int TimeGap = time - LastCommandTime;
        if (Hot > Hot_Max) {//过热
            int HotGap = Hot - Hot_Max;

            if (HotGap > TimeGap) {//热量未减至小于Max
                HP -= (HotGap * 2 - TimeGap + 1) * TimeGap / 2;
            } else {//热量减到小于Max
                HP -= HotGap * (HotGap + 1) / 2;
            }
        }
        Hot -= TimeGap;//set
        if (Hot<0){
            Hot=0;//热量不小于0
        }
    }
}

void Robot::TimeSet(int time) {
    LastCommandTime = time;
}

void Robot::TellIsDead() {
    if (HP <= 0) {//似了
        isDead = true;
        std::cout << "D " << Team << " " << Number << std::endl;
        std::cout << "TIME:" << LastCommandTime << std::endl;//<<""<<Number<<std::endl;
    }
}

