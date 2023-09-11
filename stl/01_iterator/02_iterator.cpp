#include <iostream>
#include<vector>

#include "../include/print.h"

using namespace std;


int main() {

    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it = v.begin() + 3;
    printVector(v);
    cout << *it << endl;

    v.insert(it, 8); // 动态扩容，野指针
    printVector(v);
    cout << *it << endl;

    return 0;
}
