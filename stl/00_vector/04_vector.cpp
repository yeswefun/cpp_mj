#include <iostream>
#include <vector>
#include "../include/print.h"

using namespace std;

/*
vector<T> v;
*/
int main() {

    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVector(v);

    v.pop_back();
    printVector(v);
    
    //v.insert(v.begin()+888, -1); // error
    v.insert(v.begin(), -1);
    v.insert(v.end(), -1);
    printVector(v);

    v.insert(v.begin(), 3, 0);
    v.insert(v.end(), 3, 0);
    printVector(v);

    int arr[] = {1, 2, 3, 4, 5, 6};
    v.insert(v.begin(), arr, arr+3);
    v.insert(v.end(), arr, arr+3);
    printVector(v);

    vector<int> v2(6, 9);
    v.insert(v.begin(), v2.begin(), v2.end());
    v.insert(v.end(), v2.begin(), v2.begin() + 3);
    printVector(v);

    return 0;
}
