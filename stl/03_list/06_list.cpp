#include <iostream>
#include <list>
#include "../include/print.h"

using namespace std;

/*
stack, queue 不可遍历

list 是可遍历

true，非0
false，0
*/
int main() {

    list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    printList(lst);

    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++) {
        if (*it == 3) {
            break;
        }
    }

    if (it == lst.end()) {
        cout << "not found" << endl;
    } else {
        cout << "found" << endl;
        //没有位置的移动，没有空间的释放
        //iterator没有失效
        lst.insert(it, 666);
        cout << *it << endl;
    }
    printList(lst);

    return 0;
}
