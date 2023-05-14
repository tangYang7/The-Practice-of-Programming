#include <iostream>
#include <algorithm>
using namespace std;
// reverse()
int main(){
    int32_t num = 0;
    cin >> num;
    string mystr;
    while(num){
        cin >> mystr;
        int32_t segment_num = mystr.size() / num;
        for(int32_t i = 0; i < mystr.size(); i += segment_num){
            reverse(&mystr[i], &mystr[i + segment_num]);
        }
        cout << mystr << endl;
        cin >> num;
    }

    return 0;
}
/*
3 ABCEHSHSH
5 FA0ETASINAHGRI0NATWON0QA0NARI0
0
*/
/*
CBASHEHSH
ATE0AFGHANISTAN0IRAQ0NOW0IRAN0
*/