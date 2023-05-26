#include <iostream>
#include <iterator>
#include <string.h>
using namespace std;

struct CStudent
{
   int id = 0,
       score = 0;
   char name[30] = {};
};

ostream & operator << (ostream &os, const CStudent &stu)
{
    os << stu.id << ' ' << stu.name << ' ' << stu.score;
    return os;
}

void sort(CStudent data[], int n)
{
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(data[i].id > data[j].id){
                CStudent tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}

int main() {
    CStudent data[] = {{1, 90, "David"}, {5, 100, "Allen"}, 
                        {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};
    sort(data, std::size(data));
    for (const auto &e: data) {cout << e << endl;} cout << endl;
}
