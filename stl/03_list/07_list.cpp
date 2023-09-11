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

    cout << "********************* lst" << endl;
    list<int> lst2 = lst;
    cout << "empty: " << lst.empty() << endl;
    lst.clear();
    cout << "empty: " << lst.empty() << endl;
    printList(lst);
    printList(lst2);

    cout << "********************* lst2" << endl;
    list<int> lst3 = lst2;
    //lst2.erase(lst2.begin()+1, lst2.end()); //error
    lst2.erase(lst2.begin()++, lst2.end()); // empty
    list<int>::iterator it = lst2.erase(++lst2.begin(), lst2.end()); // 1
    printList(lst2);
    cout << "it: " << (it == lst2.end()) << endl;

    cout << "********************* lst3" << endl;
    list<int> lst4 = lst3;
    printList(lst3);
    list<int>::iterator it3 = lst3.erase(++lst3.begin());
    printList(lst3);
    cout << "*it: " << *it3 << endl;
    /*
        list<int>::iterator it3 = lst3.begin();
        it3 = lst3.erase(it3); // 删除后，it3失效，需要重新赋值为新的 iterator
    */

    cout << "********************* lst4" << endl;
    lst4.push_back(2);
    printList(lst4);
    lst4.remove(2);
    printList(lst4);

    return 0;
}
