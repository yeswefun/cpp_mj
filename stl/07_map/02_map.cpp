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

    printMap(m);

    //m[666] 不存在，则添加 ""
    cout << "length: " << m[666].length() << endl;

    printMap(m);

    return 0;
}
