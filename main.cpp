#include <iostream>
#include "Robot.h"

class bubin:virtual public Robot{
public:
    bubin(int team,int number,int type): Robot(team,number,type){
        HP_Max=100;
        HP=HP_Max;
        Hot_Max=100;
    }
};

class gongcheng:virtual public Robot{
public:
    gongcheng(int team,int number,int type): Robot(team,number,type){
        HP_Max=300;
        HP=HP_Max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    bubin b(555,0,0);
    std::cout<<b.Type<<std::endl;
    std::cout<<b.Grade<<std::endl;
    std::cout<<b.Team<<std::endl;
    std::cout<<b.Number<<std::endl;
    std::cout<<b.HP_Max<<std::endl;
    std::cout<<b.Hot_Max<<std::endl;
    std::cout<<b.HP<<std::endl;
    std::cout<<b.Hot<<std::endl;
    std::cout<<b.Dead<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    gongcheng c(555,655,1);
    std::cout<<c.Type<<std::endl;
    std::cout<<c.Grade<<std::endl;
    std::cout<<c.Team<<std::endl;
    std::cout<<c.Number<<std::endl;
    std::cout<<c.HP_Max<<std::endl;
    std::cout<<c.Hot_Max<<std::endl;
    std::cout<<c.HP<<std::endl;
    std::cout<<c.Hot<<std::endl;
    std::cout<<c.Dead<<std::endl;
    return 0;
}
