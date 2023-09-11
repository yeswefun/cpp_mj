#include <iostream>
#include <vector>
#include "../include/print.h"

using namespace std;

/*
vector<T> v;
*/
int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};

    vector<int> v(arr, arr+6);
    printVector(v);

    v.front() = -1;
    v.back() = -6;
    cout << v.front() << endl;
    cout << v.back() << endl;
    printVector(v);

    /*
        v[index], 下标越界，抛出异常
            win下没有抛出异常
    */
    //v[8] = 8;
    //cout << v[8] << endl;

    //win下抛出异常
    try {
        //v.at(8) = 8;
        cout << v.at(8) << endl;
    } catch(const exception &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
