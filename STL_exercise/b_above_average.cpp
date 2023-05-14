#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip> 
using namespace std;
constexpr int MAX_LEN = 1000;
// accumulate(), count_if()

class Pred {
public:
    void Set_aver(double num){  aver_ = num; }
    bool operator()(int v) const { return v > aver_; }

private:
    double aver_ = 0;
};

int main(){

    int32_t n_case = 0;
    cin >> n_case;

    for(int32_t i = 0; i < n_case; ++i){
        int32_t num = 0;
        int32_t arr[MAX_LEN] = {0};
        cin >> num;
        for(int32_t j = 0; j < num; ++j){
            cin >> arr[j];
        }

        Pred pred;
        double aver = (accumulate(arr, end(arr), 0)) / (double)num;
        pred.Set_aver(aver);
        double result = 100 * (count_if(arr, end(arr), pred) / (double)num);

        // https://it-easy.tw/cout-float/
        cout << fixed << setprecision(3) << result << "%" << endl;
    }

    return 0;
}
/*
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91
*/
/*
40.000%
57.143%
33.333%
66.667%
55.556%
*/