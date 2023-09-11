

#ifndef PRINT_H_
#define PRINT_H_

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <iostream>

using namespace std;


void printVector(const vector<int>& v) {
    cout << "*********************" << endl;
    for (int i = 0, size = v.size(); i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


//const deque<int>& d)
//为什么加 const 修饰就不行呢?
void printDeque(deque<int>& d) {
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


void printList(list<int>& lst) {
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printSet(set<int>& s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
#endif // PRINT_H_
