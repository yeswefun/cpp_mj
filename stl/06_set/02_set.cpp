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

    cout << "********************* clear" << endl;
    set<int> s2 = s;
    cout << "size: " << s2.size() << endl;
    s2.clear();
    cout << "size: " << s2.size() << endl;

    cout << "********************* erase(pos)" << endl;
    set<int> s3 = s;
    s3.insert(4);
    s3.insert(5);
    s3.insert(6);
    cout << "size: " << s3.size() << endl;
    set<int>::iterator it3 = s3.erase(++s3.begin()); // s3.begin() == index(0)
    cout << "*it: " << *it3 << endl; // 下一个元素
    cout << "size: " << s3.size() << endl;
    
    cout << "********************* erase(beg, end)" << endl;
    set<int> s4 = s;
    cout << "size: " << s4.size() << endl;
    s4.erase(++s4.begin(), s4.end());
    cout << "size: " << s4.size() << endl;

    cout << "********************* erase(elem)" << endl;
    set<int> s5 = s;
    cout << "size: " << s5.size() << endl;
    size_t cnt = s5.erase(2);
    cout << "cnt: " << cnt << endl;
    cnt = s5.erase(666);
    cout << "cnt: " << cnt << endl;
    cout << "size: " << s5.size() << endl;

    cout << "*********************" << endl;
    set<int>::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << endl;
        it++;
    }

    return 0;
}
