#include <iostream>
#include "0602-fighter.h"

using namespace std;

int main(){
    Fighter john("john"), allen("allen");
    Monk david("david");
    Fighter *players[3] = {&john, &david, &allen};
    for (Fighter *p : players) {
    p->Display();
    }
}