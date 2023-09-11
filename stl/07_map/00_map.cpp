#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, string> m;

    // map#insert
    m.insert(pair<int, string>(1, "C++"));

    // map#value_type
    m.insert(map<int, string>::value_type(2, "Java"));

    // [], 存在则修改，不存在则插入
    m[3] = "C";

    for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
        pair<int, string> p = *it;
        cout << p.first << ":" << p.second << endl;
    }

    return 0;
}
