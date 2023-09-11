#include <iostream>
#include <set>

using namespace std;

void printSetIterator(set<int> &s, set<int>::iterator &it) {
    while (it != s.end()) {
        cout << *it++ << endl;
    }
}

int main() {

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);

    set<int>::iterator it;
    
    // find
    it = s.find(6);
    cout << *it << endl;

    it = s.find(666);
    cout << (it == s.end()) << endl;

    // count, 对于 set 存在则为1，不存在为0，对于multiset 存在可能大于1，不存在为0
    int cnt = s.count(6);
    cout << "cnt: " << cnt << endl;

    // lower_bound, 大于或等于
    cout << "*** lower_bound" << endl;
    it = s.lower_bound(3);
    printSetIterator(s, it);

    // upper_bound, 大于
    cout << "*** upper_bound" << endl;
    it = s.upper_bound(3);
    printSetIterator(s, it);

    // equal_range, not found -> s.end()
    pair<set<int>::iterator, set<int>::iterator> p = s.equal_range(3);
    cout << "*** pair#first" << endl;
    it = p.first; // lower_bound
    printSetIterator(s, it);
    cout << "*** pair#second" << endl;
    it = p.second; // upper_bound
    printSetIterator(s, it);


    return 0;
}
