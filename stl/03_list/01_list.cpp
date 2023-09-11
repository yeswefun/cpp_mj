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

    for (list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
    
    return 0;
}
