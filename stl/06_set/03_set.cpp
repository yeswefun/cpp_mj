#include <iostream>
#include <set>
#include "../include/print.h"

using namespace std;

/*
序列式容器
    vector
    deque
    list
    stack
    queue

关联式容器
    set
        multiset
    map
        multimap
*/
int main() {

    //set 容器默认是升序排列
    set<int, less<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    printSet(s);

    set<int, greater<int>> s2;
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);
    //printSet(s2); //error
    for (set<int, greater<int>>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
