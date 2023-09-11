#include <iostream>
#include <set>

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
    set<int> s;
    cout << "size: " << s.size() << endl;
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    cout << "size: " << s.size() << endl;

    cout << "*********************" << endl;
    set<int>::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << endl;
        it++;
    }

    cout << "*********************" << endl;
    set<int>::reverse_iterator rit = s.rbegin();
    while (rit != s.rend()) {
        cout << *rit << endl;
        rit++;
    }

    return 0;
}
