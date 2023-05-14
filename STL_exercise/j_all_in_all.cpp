#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

// find()
using namespace std;

int main(){
    string str1, str2;
    while(cin >> str1 >> str2){

        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()){
            int pos = str2.find(str1[i], j);
            if(pos == string::npos){
                break;
            }
            else{
                j = pos + 1;
                ++i;
            }
        }

        if(i == str1.size()){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }        
    }

    return 0;
}

/*
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
*/