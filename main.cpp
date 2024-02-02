#include <iostream>
#include <vector>
#include <memory>
#include "Robot.h"

class Bubin : virtual public Robot {
public:
    Bubin(int time, int team, int number, int type) : Robot(time, team, number, type) {
        HP_max_ = 100;
        HP_ = HP_max_;
        hot_max_ = 100;
    }
};

class Gongcheng : virtual public Robot {
public:
    Gongcheng(int time, int team, int number, int type) : Robot(time, team, number, type) {
        HP_max_ = 300;
        HP_ = HP_max_;
    }
};

class Manager {
private:
    std::vector<std::shared_ptr<Robot>> Robots;
public:

    void addRobot(int time, int team, int number, int type) {
        bool finish = false;
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_) {
                it->HotDamageAndSet(time);//热量结算
                it->TellIsDead();//生死判断
            }
            if (it->team_ == team && it->number_ == number && it->type_ == type) {
                if (it->is_dead_) {//复活
                    it->HP_ = it->HP_max_;
                    it->hot_ = 0;
                    it->is_dead_ = false;

                }
                finish = true;
            }
            it->TimeSet(time);
        }

        if (!finish) {//新建
            if (type == 0) {
                std::shared_ptr<Robot> robot = std::make_shared<Bubin>(time, team, number, type);
                Robots.push_back(robot);
            } else if (type == 1) {
                std::shared_ptr<Robot> robot = std::make_shared<Gongcheng>(time, team, number, type);
                Robots.push_back(robot);
            }
        }

    }

    void hurtRobot(int time, int team, int number, int damage) {
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_) {
                it->HotDamageAndSet(time);//热量结算
                it->TellIsDead();//生死判断
            }
            if (!it->is_dead_ && it->team_ == team && it->number_ == number) {
                it->HP_ -= damage;
                it->TellIsDead();//生死判断

            }
            it->TimeSet(time);//刷新时间
        }
    }

    void HotSet(int time, int team, int number, int hotDelta) {
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_) {
                it->HotDamageAndSet(time);//热量结算
                it->TellIsDead();//生死判断
            }
            if (!it->is_dead_ && it->type_ == 0 && it->team_ == team && it->number_ == number) {
                it->hot_ += hotDelta;
            }
            it->TimeSet(time);//刷新时间
        }
    }

    void LevelSet(int time, int team, int number, int level) {
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_) {
                it->HotDamageAndSet(time);//热量结算
                it->TellIsDead();//生死判断
            }
            if (!it->is_dead_ && it->type_ == 0 && it->team_ == team && it->number_ == number && it->level_ <= level) {

                it->level_ = level;
                it->HP_max_ = 100 + (level * 2 - 3) * 50;
                it->HP_ = it->HP_max_;
                it->hot_max_ = level * 100;
            }
            it->TimeSet(time);//刷新时间
        }
    }
};

int main() {
    Manager manager;
    int turn;
    std::cin >> turn;
    for (int i = 0; i < turn; ++i) {
        int time;
        char command;
        int team;
        int number;
        int data;
        std::cin >> time;
        std::cin >> command;
        std::cin >> team;
        std::cin >> number;
        std::cin >> data;
        switch (command) {
            case 'A':
                manager.addRobot(time, team, number, data);
                break;
            case 'F':
                manager.hurtRobot(time, team, number, data);
                break;
            case 'H':
                manager.HotSet(time, team, number, data);
                break;
            case 'U':
                manager.LevelSet(time, team, number, data);
                break;
            default:
                break;
        }
    }
    return 0;
}
