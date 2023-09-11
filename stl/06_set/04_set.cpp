#include <iostream>
#include <set>
#include "../include/print.h"

using namespace std;

int fnAdd(int x, int y) {
    return x + y;
}

int fnSub(int x, int y) {
    return x - y;
}

// int fnOp(int x, int y, int (*fn)(int, int)) {
//     return fn(x, y);
// }

typedef int (*FN)(int, int);
int fnOp(int x, int y, FN fn) {
    return fn(x, y);
}

class Op {
public:
    int operator()() {
        return m_fn(m_x, m_y);
    }
    void fnOp(int x, int y, FN fn) {
        m_x = x;
        m_y = y;
        m_fn = fn;
    }
private:
    int m_x;
    int m_y;
    FN m_fn;
};

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


less<int>
greater<int>
函数对象，也称为 伪函数, functor
*/
int main() {

    int ret;

    ret = fnOp(4, 2, fnAdd);
    cout << "add: " << ret << endl;

    ret = fnOp(4, 2, fnSub);
    cout << "sub: " << ret << endl;

    Op op;
    op.fnOp(4, 2, fnSub);
    cout << "sub: " << op() << endl;

    return 0;
}
