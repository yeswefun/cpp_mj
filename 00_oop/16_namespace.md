

命名空间 - namespace
    命名空间可以用来避免命名冲突
    命名空间不影响内存布局


```cpp
class User {
	int m_age;
public:
	void show() {
		cout << "age = " << m_age << endl;
	}
};

namespace A {

class User {
    int m_id;
public:
    void show() {
        cout << "id = " << m_id << endl;
    }
};

}
```


命名空间嵌套
    有个默认的全局命名空间，我们创建的命名空间默认都嵌套在它里面

```cpp
// ::g_no = 10;
int g_no;

namespace A {
    namespace B {
        // A::B::g_id = 20;
        int g_id = 1;
    }
}
```


```cpp
int g_no;

namespace A {
    int g_no;
}

int main() {

    using namespace A;

    g_no = 10;  // A::
    ::g_no = 10;// 全局

    return 0;
}
```



命名空间合并

```cpp
namespace A {
    int g_id = 1;
}

namespace A {
    void test() {}
}

/*
相当于下面
namespace A {
    int g_id = 1;
    void test() {}
}
*/
```



using

```cpp
namespace A {

    int g_age;

    class Person {
    };

    void test() {
    }
}
```


```cpp
int main() {
    A::g_age = 20;
    A::Person *p = new A::Person();
    A::test( );
    return 0;
}
```


```cpp
int main() {
    using namespace A;
    g_age = 20;
    Person *p = new Person();
    test();
    return 0;
}
```


```cpp
int main() {
    using A::g_age;
    g_age = 20;
    return 0;
}
```



思考

```cpp
namespace A {
    int g_age;
}
namespace B {
    int g_age;
}

int main() {
    using namespace A;
    using namespace B;
    //g_age = 20; // error
    A::g_age = 20;
    return 0;
}
```



使用

```cpp
#pragma once

namespace A {
    class User {
        public:
            User();
            ~User();
    }
}
```

一种方式
```cpp
#include "user.h"
using namespace A;

User::User() {}
User::~User() {}
```

另一种方式
```cpp
#include "user.h"
namespace A {
    User::User() {}
    User::~User() {}
}
```


```cpp
#include <iostream>
using namespace std;
// std::cout, std::endl
```



其他编程语言的命名空间
    Java
        Package
