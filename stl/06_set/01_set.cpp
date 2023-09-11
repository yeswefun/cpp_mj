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

    set<int> s2(s);
    cout << "size: " << s2.size() << endl;

    set<int> s3;
    s3 = s2;
    cout << "size: " << s3.size() << endl;

    set<int> s4;
    s4.swap(s3);
    cout << "size: " << s3.size() << endl;
    cout << "size: " << s4.size() << endl;

    cout << "*********************" << endl;
    set<int>::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << endl;
        it++;
    }

    return 0;
}
