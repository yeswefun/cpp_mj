#include <iostream>
#include<vector>

#include "../include/print.h"

using namespace std;


int main() {

    int arr[] = {1, 2, 3};

    vector<int> v(arr, arr+3);
    printVector(v);

    vector<int>::iterator it;
    it = v.begin();

    cout << "***************" << endl;
    cout << *it << endl;
    cout << *(it+1) << endl;

    cout << "***************" << endl;
    it += 2;
    cout << *it << endl;
    it -= 2;
    cout << *it << endl;
    

    cout << "***************" << endl;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }

    cout << "***************" << endl;
    it = v.begin();
    while(it != v.end()) {
        cout << *it++ << endl;
    }

    return 0;
}
