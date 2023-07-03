#ifndef FIGHTER_H__
#define FIGHTER_H__
#include <iostream>
#include <string>
class Fighter {
    public:
        Fighter(const std::string &name){
            name_ = name;
        }
        void Attack(Fighter &enemy){
            enemy.life_ -= attack_;
            exp_ += attack_;
        }
        void Display() const{
            std::cout << name_ << ": " << life_ << std::endl;
        }
        bool IsAlive() const{
            return life_ > 0;
        }
    
    protected:
        std::string name_;
        int attack_ = 3;
        int life_ = 10;
        int exp_ = 0;
};
void Battle(Fighter &x, Fighter &y){
    int random = rand() % 2;
    if(random){
        x.Attack(y);
        y.Attack(x);
    } else{
        y.Attack(x);
        x.Attack(y);
    }
}

class Monk : public Fighter{
public:
    Monk(const std::string &name) : Fighter(name){
    }
    void Heal(){
        life_ += heal_point_;
    }
private:
    int heal_point_ = 3;
};

#endif