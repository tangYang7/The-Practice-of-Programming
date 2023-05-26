#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int32_t myfunc(string str, int32_t min, int32_t k){
    for(int32_t i = 0; i < str.size(); ++i){
        if (str[(min+i)%str.size()]>str[(k+i)%str.size()]) {
            return k;
        }else if (str[(min+i)%str.size()]<str[(k+i)%str.size()]) {
            return min;
        }
    }
    return min;
}
int main(){
    int32_t n = 0;
    cin >> n;

    for(int32_t i = 0; i < n; ++i){
        string str;
        cin >> str;
        int32_t index = 0;
        for(int32_t j = 0; j < str.size(); ++j){
            index = myfunc(str, index, j);
        }

        rotate(str.begin(), str.begin()+index, str.end());
        cout << str << endl;

    }

    return 0;
}

/*
2
CGAGTCAGCT
CTCC
*/