#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
// nth_element(), accumulate()

int main(){
    int32_t N = 0;
    cin >> N;

    for(int32_t i = 0; i < N; ++i){
        int32_t r = 0;
        cin >> r;
        vector<int32_t> s(r);
        int32_t min_dist = 100;
        for(int32_t j = 0; j < r; ++j){
            cin >> s[j];
        }
        nth_element(s.begin(), s.begin()+s.size()/2, s.end());
        int32_t house = *(s.begin() + s.size()/2);
        min_dist = accumulate(s.begin(), s.end(), 0, [house] (int32_t s, int32_t t){
            s += abs(t-house);
            return s;
        } );
        // for(int32_t j = 0; j < r; ++j){
        //     cout << s[j] << " ";
        // }
        cout  << min_dist << endl;

    }

    return 0;
}
/*
2
2 2 4
3 2 4 6
*/