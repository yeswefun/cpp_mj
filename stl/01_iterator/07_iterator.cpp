#include <iostream>
#include<vector>

#include "../include/print.h"

using namespace std;


int main() {

    vector<int> v = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    printVector(v);

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); /* it++ */) {
        if (*it == 3) {
            //返回删除前的下一个位置的迭代器
            it = v.erase(it);
        } else {
            it++;
        }
    }
    printVector(v);

    return 0;
}
