#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;

    while( getline(cin, s) ){
        int32_t count_word = 0;
        for(int32_t i = 0; i < s.size(); ++i){
            if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ){
                if(i == 0){
                    ++count_word;
                    // cout << s[i] << ' ';
                }else if((s[i-1] < 'A' || s[i-1] > 'Z') && (s[i-1] < 'a' | s[i-1] > 'z')){
                    ++count_word;
                    // cout << s[i] << ' ';
                }
            }
        }
        cout << count_word << endl;
    }

    return 0;
}
/*
Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...
*/