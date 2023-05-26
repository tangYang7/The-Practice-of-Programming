#include <iostream>
#include <iterator>
using namespace std;

// TODO: function template print()
template <typename T>
void print(const T *begin, const T *end)
{
    while (begin != end) {
        cout << *begin << ' ';
        ++begin;
    }
}

// TODO: function template min_element()
template <typename T>
T min_element(T begin, const T end){
    T min = begin;
    while(begin != end){
        if(*min > *begin) *min = *begin;
        ++begin;
    }
    return min;
}
int main ()
{
    int i[3] = {3, 1, 2};
    double d[5] = {5.4, 3.2, 1.2, 4.5, 5.6};
    char c[4] = {'S', 'I', 'E', 'C'};

    print(i, (i+3)); cout << endl;
    print(d, (d+5)); cout << endl;
    print(c, (c+4)); cout << endl;

//    print(i, 3); // error!

    cout << *min_element(i, (i+3)) << endl;
    cout << *min_element(d, (d+5)) << endl;
    cout << *min_element(c, (c+4)) << endl;
}