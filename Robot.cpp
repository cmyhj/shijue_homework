//
// Created by CMYHJ on 2024/1/31.
//
#include "Robot.h"

using namespace std;

Robot::Robot(int team, int number, int type) {
    team_ = team;
    number_ = number;
    type_ = type;
}

void Robot::HotDamageAndSet() {
    if (!is_dead_) {//找到对应机器人
        /*int TimeGap = time - last_command_time_;
        if (hot_ > hot_max_) {//过热
            int HotGap = hot_ - hot_max_;

            if (HotGap > TimeGap) {//热量未减至小于Max
                HP_ -= (HotGap * 2 - TimeGap + 1) * TimeGap / 2;
            } else {//热量减到小于Max
                HP_ -= HotGap * (HotGap + 1) / 2;
            }
        }
        hot_ -= TimeGap;//set
        if (hot_ < 0) {
            hot_ = 0;//热量不小于0
        }*/
        if (hot_ > hot_max_) {//过热
            HP_ -= (hot_ - hot_max_);
        }
        hot_--;
        if (hot_ < 0) {//热量不小于0
            hot_ = 0;
        }
    }
}


void Robot::TellIsDead() {
    if (HP_ <= 0) {//似了
        is_dead_ = true;
        std::cout << "D " << team_ << " " << number_ << std::endl;
    }
}

