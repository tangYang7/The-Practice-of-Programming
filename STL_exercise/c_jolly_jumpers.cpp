#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

// adjacent_difference(), all_of()
using namespace std;

int main(){
    int32_t n = 0;
    while(cin >> n){
        vector<int> vec(n);
        vector<int> diff(n);
        vector<int> one(n);

        for(int32_t i = 0; i < vec.size(); ++i){
            cin >> vec[i];
        }
        if(vec.size() == 1){
            cout << "Jolly" << endl;
            continue;
        }

        adjacent_difference(vec.begin(), vec.end(), diff.begin() );
        for(int32_t i = 0; i < diff.size(); ++i){
            diff[i] = abs(diff[i]);
        }
        diff.erase(diff.begin());
        if(diff.size() == 1){
            if(diff[0] == 1){
                cout << "Jolly" << endl;
            } else {
                cout << "Not jolly" << endl;
            }
            continue;
        }
        sort(diff.begin(), diff.end());
        adjacent_difference(diff.begin(), diff.end(), one.begin() );
        one.erase(one.begin());
        one.erase(one.end()-1);
        
    //     for(int32_t i = 0; i < diff.size(); ++i){
    //         cout << diff[i] << " ";
    //     }
    //     cout << endl;
    //     for(int32_t i = 0; i < one.size(); ++i){
    //         cout << one[i] << " ";
    //     }
    //    cout << endl;
 
        if(all_of(one.begin(), one.end(), [](int32_t s){
            if(s == 1)  return true;
            return false;
        })){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;

        }
    }
    return 0;
}
/*
4 1 4 2 3
5 1 4 2 -1 6
*/