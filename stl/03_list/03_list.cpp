#include <iostream>
#include <list>
#include "../include/print.h"

using namespace std;

/*
stack, queue 不可遍历

list 是可遍历
*/
int main() {

    list<int> lst1;
    lst1.assign(3, 6);
    printList(lst1);

    list<int> lst2;
    lst2.assign(3, 8);
    printList(lst2);

    lst1.swap(lst2);
    printList(lst1);
    printList(lst2);

    return 0;
}
