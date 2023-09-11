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

    it = v.insert(it, 8); // insert 可能会返回一个新的有效的迭代器
    printVector(v);
    cout << *it << endl;

    return 0;
}
