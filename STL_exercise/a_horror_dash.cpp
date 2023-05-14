#include <iostream>
#include <algorithm>
using namespace std;    // max_element()
constexpr int MAX_LEN = 100;
    
int main(){

    int n_case = 0;
    cin >> n_case;

    int num = 0;
    int arr[MAX_LEN] = {0};
    for(int32_t i = 0; i < n_case; ++i){
        cin >> num;
        for(int32_t j = 0; j < num; ++j){
            cin >> arr[j];
        }
        cout << "Case " << i+1 << ": " << *max_element(arr, arr+num) << endl;
    }

    return 0;
}
/*
2
5 9 3 5 2 6
1 2
*/
/*
Case 1: 9
Case 2: 2
*/