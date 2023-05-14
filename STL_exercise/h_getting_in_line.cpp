#include <iostream>
#include <algorithm>
#include <numeric>
// #include <vector>
#include <string>
#include <cmath>
#include <iomanip> 

// iota(), copy(), next_permutation()
using namespace std;

int main(){
    int32_t n = 1;
    int32_t count = 0;
    while(cin >> n){
        if(!n)   break;
        cout << "**********************************************************" << endl;
        cout << "Network #" << ++count << endl;
        // int32_t x[n] = {0}, y[n] = {0}, num[n] = {0}, perm[n] = {0};
        int32_t x[n] = {0}, y[n] = {0};
        int32_t num[n] = {0}, result[n] = {0};
        
        double min_sum = 100000000.0;
        for(int32_t i = 0; i < n; ++i){
            cin >> x[i] >> y[i];
        }
        iota(num, num+n, 0);

        do{
            double sum = 0.0;
            for(int32_t i = 1; i < n; ++i){
                sum += sqrt(pow(x[num[i]] - x[num[i-1]], 2) + pow(y[num[i]] - y[num[i-1]], 2)) + 16.0;
            }
            if(sum < min_sum){
                min_sum = sum;
                copy(num, num+n, result);
            }
        } while(next_permutation(num, num+n));

        for(int32_t i = 1; i < n; ++i){
            cout << fixed << setprecision(2) << "Cable requirement to connect (" << x[result[i-1]] << "," << y[result[i-1]];
            cout << ") to (" << x[result[i]] << "," << y[result[i]] << ") is ";
            cout << sqrt(pow(x[result[i]] - x[result[i-1]], 2) + pow(y[result[i]] - y[result[i-1]], 2)) + 16.0 << " feet." << endl;
        }
        cout << "Number of feet of cable required is " << min_sum << "." << endl;
        
    }

    return 0;
}

/*
6
5 19
55 28
38 101
28 62
111 84
43 116
5
11 27
84 99
142 81
88 30
95 38
3
132 73
49 86
72 111
0

*/