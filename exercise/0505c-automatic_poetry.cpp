#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int find_loc(string str, int32_t &loc1, int32_t &loc2){
    for(int32_t i = loc1; i < str.size(); ++i){
        if(str[i] == '<'){
            loc1 = i+1;
            break;
        }
    }
    for(int32_t i = loc1; i < str.size(); ++i){
        if(str[i] == '>'){
            loc2 = i;
            break;
        }
    }
    return -1;
}
int main(){
    int32_t n = 0;
    cin >> n;
    cin.get();
    for(int32_t i = 0; i < n; ++i){
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
// str1
        int32_t loc1 = 0, loc2 = 0;
        string tmp1, tmp2;
        find_loc(str1, loc1, loc2);
    // cout << loc1 << " " << loc2 << endl;

        tmp1 = str1.substr(loc1, loc2 - loc1);
        string str3 = str1.substr(loc2+1, str1.size() - loc1);
        str1.erase(--loc1, 1);
        str1.erase(--loc2, 1);

        find_loc(str1, loc1, loc2);
    // cout << loc1 << " " << loc2 << endl;
        tmp2 = str1.substr(loc1, loc2 - loc1);
    // cout << tmp1 << " " << tmp2 << endl;

        --loc1, --loc2;
        str1.erase(loc1, 1);
        str1.erase(loc2, 1);
        str3.insert(0, tmp2);
        
        loc1 = 0, loc2 = 0;
        find_loc(str3, loc1, loc2);
        --loc1;
        str3.erase(loc1, loc2 - loc1+1);
        str3.insert(loc1, tmp1);
// str2
        loc2 = str2.find("...");
        str2.erase(loc2, 3);
        str2.insert(loc2, str3);

        cout << str1 << endl;
        cout << str2 << endl;
        // cout << str3 << endl;        
        // cout << endl;
    }

    return 0;
}
/*
3
ein kind haelt seinen <schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...
*/