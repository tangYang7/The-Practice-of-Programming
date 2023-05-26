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
template <typename T>
// void sort(CStudent data[], int n) {
//     for(int i = 0; i < n; ++i){
//         for(int j = i; j < n; ++j){
//             if(data[i].id > data[j].id){
//                 CStudent tmp = data[i];
//                 data[i] = data[j];
//                 data[j] = tmp;
//             }
//         }
//     }
// }
void sort(T data[], int n) {
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(data[i] > data[j]){
                T tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}
int main() {
    CStudent data[] = {{1, 90, "David"}, {5, 100, "Allen"}, 
                        {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};
    // sort(data, 5);
    int arr1[5] = {1, 9, 5, 6, 3};
    double arr2[5] = {1.2, 9.3, 4.5, 3.6, 7.3};
    // const int arr3[5] = {1, 9, 5, 6, 3};
    sort(arr1, 5);
    sort(arr2, 5);
    // sort(arr3, 5);
    for (const auto &e: arr1) {cout << e << endl;} cout << endl;
    for (const auto &e: arr2) {cout << e << endl;} cout << endl;
    // for (const auto &e: arr3) {cout << e << endl;} cout << endl;

    // for (const auto &e: data) {cout << e << endl;} cout << endl;
}
