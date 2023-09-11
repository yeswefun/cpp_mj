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
    cout << lst.size() << endl;
    cout << lst.empty() << endl;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    cout << lst.size() << endl;
    cout << lst.empty() << endl;

    lst.push_back(11);
    lst.push_back(22);
    lst.push_back(33);
    printList(lst);

    list<int> lst2 = lst;
    list<int> lst3 = lst;
    lst.resize(3);
    printList(lst);

    lst2.resize(10);
    printList(lst2);

    lst3.resize(10, 1);
    printList(lst3);

    //lst3.resize(lst3.size() + 6, 8);

    return 0;
}
