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

    //list.insert(pos, elem) -> iterator
    lst.insert(lst.begin(), 1);
    lst.insert(lst.begin(), 2);
    lst.insert(lst.begin(), 3);
    printList(lst);

    lst.insert(lst.end(), -1);
    lst.insert(lst.end(), -2);
    lst.insert(lst.end(), -3);
    printList(lst);

    lst.resize(3);
    printList(lst);

    //insert
    lst.insert(lst.begin(), 3, 6);
    printList(lst);

    //insert
    list<int> lst2(3, 8);
    lst.insert(lst.end(), lst2.begin(), lst2.end());
    printList(lst);

    return 0;
}
