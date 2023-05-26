#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    string str;
    // while(!cin.eof()){
    while(getline(cin, str)){
        // getline(cin, str);
        
        // cout << str << endl;
        istringstream iss(str);
        string tmp;
        int32_t count = 0;
        while(iss >> tmp){
            if(count != 0)  cout << " ";
            reverse(tmp.begin(), tmp.end());
            cout << tmp;
            ++count;
        }
        cout << endl;
    }


    return 0;
}
/*
I love you.
You love me.
We're a happy family.
*/