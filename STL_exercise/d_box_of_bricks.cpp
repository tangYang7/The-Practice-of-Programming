#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
constexpr int MAX_N = 50;
int main(){
    int n;
    int cnt = 0;
    cin >> n;
    while(n){
        int h[MAX_N] = {0};
        for(int32_t i = 0; i<n; ++i){
            cin >> h[i];
        }

        int aver = accumulate(h, end(h), 0) / n;
        int result = 0;
        // cout << "aver: " << aver << endl;
        for(int32_t i = 0; i<n; ++i){
            if(h[i] > aver){
                result += h[i] - aver;
            }
        }
        cout << "Set #" << ++cnt << endl;
        cout << "The minimum number of moves is " << result << "." << endl;
        cout << endl;
        cin >> n;
    }

    return 0;
}

/*
6
5 2 4 1 7 5
0
*/
/*
Set #1
The minimum number of moves is 5.
*/