#include <iostream>
#include <queue>

using namespace std;

/*
队列
    入队时，总是从队尾进行
    出队时，总是从队头进行
*/
int main() {

    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    // q.front() == 666;
    // q.back() == 888;

    queue<int> q2(q);
    cout << "size: " << q2.size() << endl;
    q2.pop();
    cout << "size: " << q2.size() << endl;

    queue<int> q3;
    q3 = q2;
    cout << "size: " << q3.size() << endl;
    q3.push(4);
    cout << "size: " << q3.size() << endl;


    while(!q.empty()) {
        cout << q.front() << endl;       
        q.pop();
    }

    return 0;
}
