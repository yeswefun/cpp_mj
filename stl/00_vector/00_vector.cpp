#include <iostream>
#include <vector>
#include "../include/print.h"

using namespace std;

/*
vector<T> v;
*/
int main() {

    //[begin, end)
    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> v1(arr, arr+6);
    printVector(v1);

    // 3个10
    vector<int> v2(3, 10);
    printVector(v2);

    //vectory<int> v3 = v1;
    vector<int> v3(v1);
    printVector(v3);

    return 0;
}
