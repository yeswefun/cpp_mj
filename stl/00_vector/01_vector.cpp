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
    v1.assign(arr, arr+6);
    printVector(v1);

    vector<int> v2(3, 6);
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(v1.begin()+2, v1.end()-1); // 3, 4, 5
    printVector(v4);

    vector<int> v5;
    v5.assign(3, 8);
    printVector(v5);

    vector<int> v6;
    v6 = v5;
    v6[1] = 888;
    printVector(v5);
    printVector(v6);

    cout << "------------------------------------------" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
    printVector(v3);

    return 0;
}
