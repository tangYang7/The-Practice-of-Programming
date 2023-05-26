#include <iostream>
#include <string>
#include<algorithm>
#include <cctype>
using namespace std;
std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
       [](unsigned char c){ return std::tolower(c); }
    );
    return s;
}
int main(){
    string str[1000], sorted[1000];
    int32_t count = 0;
    while(cin >> str[count]){
        if(str[count] == "#"){
            break;
        }
        ++count;
    }
    sort(str, str+count);
    for(int32_t i = 0; i < count; ++i){
        sorted[i] = str[i];
        sorted[i] = toLower(sorted[i]);
        sort(sorted[i].begin(), sorted[i].end());
    }

    for(int32_t i = 0; i < count; ++i){
        bool flag = true;
        for(int32_t j = 0; j < count; ++j){
            if(i == j){
                continue;
            }
            if(sorted[i] == sorted[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << str[i] << endl;
        }

    }
    return 0;
}
/*
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#
*/