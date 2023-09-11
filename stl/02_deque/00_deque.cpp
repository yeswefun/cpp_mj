#include <iostream>
#include <deque>
#include "../include/print.h"

using namespace std;


/*
deque 的接口 与 vector 的接口几乎一样

vector
    元素地址连续

deque
    元素地址不一定连续


vector 与 deque
    动态数组
        动态扩容，动态缩容
    利用下标访问元素
*/
int main() {

    deque<int> d = {1, 2, 3};

    d.push_front(-1);
    printDeque(d);

    d.pop_front();
    printDeque(d);

    d.erase(d.begin());
    printDeque(d);

    return 0;
}
