#include <iostream>
#include <set>

using namespace std;

class Stud {
    friend class StudFunctor;
    friend ostream& operator<<(ostream& out, const Stud &stud);
public:
    Stud(int id, string name) : m_id(id), m_name(name) {
    }
private:
    int m_id;
    string m_name;
};

ostream& operator<<(ostream& out, const Stud &stud) {
    return out << stud.m_id << ":" << stud.m_name;
}


//伪函数类
class StudFunctor {
public:
    bool operator()(const Stud &s1, const Stud &s2) {
        //升序
        return s1.m_id < s2.m_id;
        //降序
        //return s1.m_id > s2.m_id;
    }
};


int main() {

    set<Stud, StudFunctor> s;
    s.insert(Stud(666, "Golang"));
    s.insert(Stud(111, "C"));
    s.insert(Stud(888, "C++"));
    s.insert(Stud(333, "Java"));
    s.insert(Stud(222, "Smali"));
    s.insert(Stud(444, "Arm"));

    for (set<Stud, StudFunctor>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
