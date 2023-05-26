#include <iostream>
#include <string.h>
#include <iterator>
using namespace std;

struct CStudent {
   int id = 0,
       score = 0;
   char name[30] = {};
};

ostream & operator << (ostream &os, const CStudent &stu)
{
    os << stu.id << ' ' << stu.name << ' ' << stu.score;
    return os;
}

using FunctionType = int (*) (const CStudent &, const CStudent &);

void sort(CStudent data[], int n, FunctionType Compare) {
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if( Compare(data[i], data[j]) ){
                CStudent tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}

int CompareId(const CStudent &lhs, const CStudent &rhs){
    return lhs.id > rhs.id;
}
int CompareName(const CStudent &lhs, const CStudent &rhs){
    if(string(lhs.name) > string(rhs.name))
        return 1;
    else
        return 0;
}
int CompareScore(const CStudent &lhs, const CStudent &rhs){
    return lhs.score > rhs.score;
}

int main() {
    CStudent data[] = {{1, 90, "David"}, {5, 100, "Allen"}, {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};

    sort(data, 5, CompareId);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, 5, CompareName);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, 5, CompareScore);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
}