#include <iostream>
#include <algorithm>
#include "String.h"
#include <string>

using namespace std;
int main() {
    String s;
    string ss;
    int32_t n = 0;
    // stage 1: operator[], c_str(), and size()
    cout << endl << "stage " << ++n << ": operator[], c_str(), and size()" << endl;
    cout << "Expect: ";
    cout << ss[0] << ss.c_str() << ss.size() << endl;
    cout << "Actual: ";
    cout << s[0] << s.c_str() << s.size() << endl;

    ss = "hello", s = "hello";
    cout << "Expect: ";
    cout << ss[0] << ss.c_str() << ss.size() << endl;
    cout << "Actual: ";
    cout << s[0] << s.c_str() << s.size() << endl;

    // stage 2: default constructor
    cout << endl << "stage " << ++n  << ": default constructor" << endl;
    String s2("CSIE113");
    string S2("CSIE113");
    s2[3] = '\0';
    S2[3] = '\0';
    cout << "Expect: ";
    cout << S2 << " " << S2[4] << endl;
    cout << "Actual: ";
    cout << s2 << " " << s2[4] << endl;
    cout << "Expect: ";
    cout << S2.c_str() << " " << S2[4] << endl;
    cout << "Actual: ";
    cout << s2.c_str() << " " << s2[4] << endl;

    // stage 3: copy constructor
    cout << endl << "stage " << ++n << ": copy constructor" << endl;
    String s3("CSIE"), t(s3);
    string S3("CSIE"), T(S3);
    t[0] = 'X', T[0] = 'X';
    t += "113", T += "113";
    cout << "Expect: ";
    cout << S3 << ' ' << T << endl;
    cout << "Actual: ";
    cout << s3 << ' ' << t << endl;

    // stage 4: = operator
    cout << endl << "stage " << ++n << ": = operator" << endl;
    String s4("test"), t2;
    string S4("test"), T2;
    t2 = s4, T2 = S4;
    t2[2] = '3', T2[2] = '3';
    cout << "Expect: ";
    cout << S4 << ' ' << T2 << endl;
    cout << "Actual: ";
    cout << s4 << ' ' << t2 << endl;

    // stage 5: clear()
    cout << endl << "stage " << ++n << ": clear()" << endl;
    s3.clear();
    S3.clear();
    cout << "Expect: ";
    cout << S3 << endl;
    cout << S3[0] << S3.c_str() << S3.size() << endl;
    cout << "Actual: ";
    cout << s3 << endl;
    cout << s3[0] << s3.c_str() << s3.size() << endl;


    // stage 6: >> operator
    String s6;
    cout << endl << "stage " << ++n << ": >> operator" << endl;
    // cout << "Please input a string: ";
    // cin >> s6;
    // cout << "Your input: " << s6 << endl;

    // stage 7: swap()
    cout << endl << "stage " << ++n << ": swap()" << endl;
    String s8("CSIE"), t8("123");
    string S8("CSIE"), T8("123");
    cout << s8 << ' ' << t8 << endl;
    s8.swap(t8);
    S8.swap(T8);
    cout << "Expect:";
    cout << S8 << ' ' << T8 << endl;
    cout << "Actual:";
    cout << s8 << ' ' << t8 << endl;
    const String sss("CCC");
    const string SSS("CCC");
    s8 = sss, S8 = SSS;
    cout << "Expect:";
    cout << S8 << endl;
    cout << "Actual:";
    cout << s8 << endl;

    // stage 8: + operator
    cout << endl << "stage " << ++n << ": + operator" << endl;
    String s10("CSIE"), tt("113");
    string S10("CSIE"), TT("113");
    cout << "Expect: ";
    cout << S10 + TT << endl;
    cout << "Actual: ";
    cout << s10 + tt << endl;
    

    // stage 9: relational operators
    cout << endl << "stage " << ++n << ": relational operators" << endl;
    String s11("DSIE"), t11("CSIE3");
    string S11("DSIE"), T11("CSIE3");
    cout << "size: " << s11.size()  << " "<< t11.size() << endl;
    cout << "< : "<< (s11 <  t11) << " / " << (S11 <  T11)<< endl;
    cout << "> : "<< (s11 >  t11) << " / " << (S11 >  T11)<< endl;
    cout << "<=: "<< (s11 <= t11) << " / " << (S11 <= T11)<< endl;
    cout << ">=: "<< (s11 >= t11) << " / " << (S11 >= T11)<< endl;
    cout << "==: "<< (s11 == t11) << " / " << (S11 == T11)<< endl;
    cout << "!=: "<< (s11 != t11) << " / " << (S11 != T11)<< endl;

    cout << "--------------" << endl;

    // stage 11: destructor
    cout << endl << "stage " << ++n << ": destructor" << endl;
    for (int i=0; i<1e9; i+=1) { String s11("CSIE"); }
    cout << "--------------" << endl;
    return 0;
}
