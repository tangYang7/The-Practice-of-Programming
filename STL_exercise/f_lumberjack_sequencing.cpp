#include <iostream>
#include <algorithm>
using namespace std;
constexpr int32_t LEN = 10;

int main(){
    int32_t N = 0;
    cin >> N;

    cout << "Lumberjacks:" << endl;
    for(int32_t i = 0; i < N; ++i){
        int32_t num[LEN] = {0};
        for(int32_t j = 0; j < LEN; ++j){
            cin >> num[j];
        }

        if( is_sorted(num, end(num)) ) {
            cout << "Ordered" << endl;
        } else if( is_sorted(num, end(num), [](int32_t a, int32_t b ){ return a>b;}  ) ) {
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }

    }

    return 0;
}

/*
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18
*/