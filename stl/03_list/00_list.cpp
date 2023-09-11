#include <iostream>
#include <list>
#include "../include/print.h"

using namespace std;

/*
stack, queue 不可遍历

list 是可遍历
*/
int main() {

    list<int> lst;
    
    lst.push_back(-1);
    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    printList(lst);
    cout << "front: " << lst.front() << endl;
    cout << "back: " << lst.back() << endl;

    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    printList(lst);

    lst.pop_back();
    lst.pop_back();
    lst.pop_back();
    printList(lst);
    
    lst.pop_front();
    lst.pop_front();
    lst.pop_front();
    printList(lst);

    cout << "front: " << lst.front() << endl;
    cout << "back: " << lst.back() << endl;

    lst.front() = 666;
    lst.back() = 888;
    cout << "front: " << lst.front() << endl;
    cout << "back: " << lst.back() << endl;
    
    return 0;
}
