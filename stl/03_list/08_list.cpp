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

    lst.reverse();
    printList(lst);

    return 0;
}
