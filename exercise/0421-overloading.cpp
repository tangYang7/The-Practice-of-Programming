#include <stdio.h>

class Monster
{
public:
    void Create(int attack)
    {
        attack_ = attack;
        evolution_times_ = 1;
    }

    double Power() const
    {
        return evolution_times_ > 0 ? attack_/evolution_times_ : 0;
    }

// TODO: operator <
    bool operator < (const Monster& monster) const
    {
        return this->Power() < monster.Power();
    }
// TODO: operator +=
    Monster &operator += (const Monster& monster)  //noted: return type is Monster&!!!
    {
        this->attack_ += monster.attack_;
        this->evolution_times_ += monster.evolution_times_;
        return *this;
        
    }
// TODO: operator +
    Monster operator + (const Monster& monster) const // (a+b) = c will error if const this function 
    {
        Monster tmp = *this;
        tmp += monster;
        return tmp;
    };
private:
    int evolution_times_ = 0;
    double attack_ = 0;
};

int main()
{
    Monster bigfoot, vampire, slime;

    bigfoot.Create(40);
    vampire.Create(50);
    slime.Create(56);

    if (bigfoot < vampire && !(slime < vampire))
    {
        printf("Great! You may overload operator < correctly.\n");
    }

    Monster tmp = slime;
    (bigfoot += slime) += slime; // (40+56+56)/3

    if (tmp < slime || slime < tmp)
    {
        printf("Oh no, you should not modify slime.\n");
    }
    if (vampire < bigfoot)  // 50 < (40+56+56)/3
    {
        printf("Great! You may overload operator += correctly.\n");
    }
    if (bigfoot < vampire + slime) // 152/3 < 116/2
    {
        printf("Good. You have done the first step for overloading operator +.\n");
    }
    if (bigfoot < vampire) // 152/3 > 50/1
    {
        printf("Oh no, you should not modify vampire.\n");
    }
}

