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

    lst.push_back(2);
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ) { // it++
        if (*it == 2) {
            //it++, 需要 节点的next, 但 it 指向的数据已经被释放，可能是无效值
            // 插入 并不会使 iterator 失效，只有 删除元素 会
            it = lst.erase(it);
        } else {
            it++;
        }
    }
    printList(lst);

    return 0;
}
