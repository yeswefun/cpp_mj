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

    // map#insert
    m.insert(pair<int, string>(1, "C++"));

    // map#value_type
    m.insert(map<int, string>::value_type(2, "Java"));
    m.insert(map<int, string>::value_type(2, "Xxxx")); // ignore

    printMap(m);

    // [], 存在则修改，不存在则插入
    m[3] = "C";
    m[3] = "Python"; // modify

    printMap(m);

    return 0;
}
