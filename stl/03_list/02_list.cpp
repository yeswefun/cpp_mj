#include <iostream>
#include <list>
#include "../include/print.h"

using namespace std;

/*
stack, queue 不可遍历

list 是可遍历
*/
int main() {

    list<int> lst1(3, 6);
    printList(lst1);
  
    int arr[] = {1, 2, 3};
    list<int> lst2(arr, arr+3);
    printList(lst2);

    //不支持 +n, 支持 ++
    //list<int> lst3(lst2.begin()+1, lst2.begin()+2); // error
    list<int> lst3(lst2.begin(), lst2.end());
    printList(lst3);

    list<int> lst4(lst2.rbegin(), lst2.rend());
    printList(lst4);

    //list<int> lst5 = lst4;
    list<int> lst5(lst4);
    printList(lst5);

    return 0;
}
