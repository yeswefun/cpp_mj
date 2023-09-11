#include <iostream>
#include <vector>
#include "../include/print.h"

using namespace std;

/*
vector<T> v;
*/
int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};

    vector<int> v1;
    cout << v1.size() << endl;
    cout << v1.empty() << endl;

    v1.assign(arr, arr+6);
    cout << v1.size() << endl;
    cout << v1.empty() << endl;
    printVector(v1);

    vector<int> v2 = v1;
    vector<int> v3 = v1;
    
    //shrink
    v1.resize(2);
    printVector(v1);

    //expand
    v2.resize(10);
    printVector(v2);

    //expand
    v3.resize(10, 1);
    printVector(v3);

    return 0;
}
