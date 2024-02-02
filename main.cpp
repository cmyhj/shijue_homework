#include <iostream>
#include <vector>
#include <memory>
#include "Robot.h"

class BuBin : virtual public Robot {
public:
    BuBin(int team, int number, int type) : Robot(team, number, type) {
        HP_max_ = 100;
        HP_ = HP_max_;
        hot_max_ = 100;
    }
};

class GongCheng : virtual public Robot {
public:
    GongCheng(int team, int number, int type) : Robot(team, number, type) {
        HP_max_ = 300;
        HP_ = HP_max_;
    }
};

class Manager {
private:
    std::vector<std::shared_ptr<Robot>> Robots;
public:

    void HotDot() {
        for (auto &it: Robots) {
            if (!it->is_dead_) {
                it->HotDamageAndSet();//热量结算
                it->TellIsDead();//生死判断
            }
        }
    }

    void AddRobot(int team, int number, int type) {
        bool finish = false;
        for (auto &it: Robots) {//在池中寻找
            if (it->team_ == team && it->number_ == number && it->type_ == type) {
                if (it->is_dead_) {//复活
                    it->HP_ = it->HP_max_;
                    it->hot_ = 0;
                    it->is_dead_ = false;

                }
                finish = true;
            }
        }

        if (!finish) {//新建
            if (type == 0) {
                std::shared_ptr<Robot> robot = std::make_shared<BuBin>(team, number, type);
                Robots.push_back(robot);
            } else if (type == 1) {
                std::shared_ptr<Robot> robot = std::make_shared<GongCheng>(team, number, type);
                Robots.push_back(robot);
            }
        }

    }

    void HurtRobot(int team, int number, int damage) {
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_ && it->team_ == team && it->number_ == number) {
                it->HP_ -= damage;
                it->TellIsDead();//生死判断
            }
        }
    }

    void HotSet(int team, int number, int hotDelta) {
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_ && it->type_ == 0 && it->team_ == team && it->number_ == number) {
                it->hot_ += hotDelta;
            }
        }
    }

    void LevelSet(int team, int number, int level) {
        for (auto &it: Robots) {//在池中寻找
            if (!it->is_dead_ && it->type_ == 0 && it->team_ == team && it->number_ == number && it->level_ <= level) {

                it->level_ = level;
                it->HP_max_ = 100 + (level * 2 - 3) * 50;
                it->HP_ = it->HP_max_;
                it->hot_max_ = level * 100;
            }
        }
    }
};

int main() {
    Manager manager;
    int turn;
    int last_time = 0;
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
        for (int now_time = last_time; now_time < time; ++now_time) {
            manager.HotDot();
        }
        switch (command) {
            case 'A':
                manager.AddRobot(team, number, data);
                break;
            case 'F':
                manager.HurtRobot(team, number, data);
                break;
            case 'H':
                manager.HotSet(team, number, data);
                break;
            case 'U':
                manager.LevelSet(team, number, data);
                break;
            default:
                break;
        }
        last_time = time;
    }
    return 0;
}
