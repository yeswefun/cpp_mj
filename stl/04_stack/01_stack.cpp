#include <iostream>
#include <stack>

using namespace std;

/*
stack 是 一种 操作受限 的容器
    操作只能在 栈顶 进行
*/
int main() {

    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);

    //copy constructor
    stack<int> s2 = s;
    cout << "size: " << s2.size() << endl;
    s2.pop();
    cout << "size: " << s2.size() << endl;

    stack<int> s3;
    s3 = s2;
    cout << "size: " << s3.size() << endl;
    s3.push(666);
    cout << "size: " << s3.size() << endl;


    //stack容器没有迭代器，因为栈只可以操作栈顶元素
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
