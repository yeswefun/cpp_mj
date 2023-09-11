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

    while(!q.empty()) {
        cout << q.front() << endl;       
        q.pop();
    }

    return 0;
}
