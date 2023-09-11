#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, string> m) {
    cout << "************" << endl;
    for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
        pair<int, string> p = *it;
        cout << p.first << ":" << p.second << endl;
    }
}

int main() {

    map<int, string> m;
    m[1] = "Java";
    m[2] = "C++";
    m[3] = "Python";
    m[4] = "C";
    printMap(m);

    //m[1] // 不存在，则添加

    map<int, string>::iterator it;

    //推荐使用这种方式
    cout << "************ find" << endl;
    it = m.find(3);
    cout << (it != m.end()) << endl;

    it = m.find(8);
    cout << (it != m.end()) << endl;

    cout << "************ at" << endl;
    cout << m.at(3) << endl;
    cout << m.at(6) << endl;

    return 0;
}
