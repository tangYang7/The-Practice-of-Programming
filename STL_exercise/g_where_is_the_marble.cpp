#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// sort(), lower_bound()

int main(){
    int32_t N = 0, Q = 0;
    int32_t count = 0;
    while(cin >> N >> Q){
        if(N == 0 && Q == 0){
            break;
        }
        cout << "CASE# " << ++count << ":" << endl;
        int32_t marble[N];
        int32_t query[Q];
        for(int32_t j = 0; j < N; ++j){
            cin >> marble[j];
        }
        vector<int32_t> v(marble, marble+N);
        sort(marble, marble + N);

        for(int32_t j = 0; j < Q; ++j){
            cin >> query[j];
            int32_t *result = lower_bound(marble, marble + N, query[j]);
            
            if(*result == query[j] ) {
                cout << query[j] << " found at " << distance(marble, result)+1 << endl;
            } else {
                cout << query[j] << " not found" << endl;
            }
        }

    }


    return 0;
}

/*
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
*/