


面向对象
    类，对象
        成员变量(属性)
        成员函数(方法)
    
    封装，继承，多态




类
    C++中可以使用struct、class来定义一个类
        struct和class的区别
            struct的默认成员权限是public
            class的默认成员权限是private

    实际开发中，用class表示类比较多

    下面代码中 User对象、User指针的内存都是在函数的栈空间，自动分配和回收的

```cpp
struct User {
    int id;

    void test() {
        cout << id << endl;
    }
};

int main() {
    User u;
    u.id = 10;
    u.test();
    return 0;
}
```


```cpp
class User {
public:
    int id;

    void test() {
        cout << id << endl;
    }
};

int main() {
    User *p = new User();
    p->id = 10;
    p->test();
    return 0;
}
```



编程规范

```
变量名规范参考
    全局变量：g_
    成员变量：m_
    静态变量：s_
    常量：c_
    使用驼峰标识
```



对象的内存布局
	如果类中有多个成员变量，对象的内存又是如何布局的?

    全局区 == 数据段
        size

    内存对齐

```cpp
struct Test {
	int m_id;
	int m_age;
	int m_height;

	void display() {
		cout << "id = " << m_id
			<< ", age = " << m_age
			<< ", height = " << m_height
			<< endl;
	}
};

int main() {
	/*
        12
        &t: 00CFFA98
        &t.m_id: 00CFFA98
        &t.m_age: 00CFFA9C
        &t.m_height: 00CFFAA0
        调试 / 窗口 / 内存 / 将内存地址粘贴查看
	*/
	cout << sizeof(Test) << endl;
	Test t;
	t.m_id = 1;
	t.m_age = 2;
	t.m_height = 3;
	cout << "&t: " << &t << endl;
	cout << "&t.m_id: " << &t.m_id << endl;
	cout << "&t.m_age: " << &t.m_age << endl;
	cout << "&t.m_height: " << &t.m_height << endl;
    return 0;
}
```


```cpp
struct Person {
	// 每个对象都有独自一份 id
	int id;

	// 所有对象共用一个 getId()，使用 this 来标识当前对象
	int getId() {
		return id;
	}
};
```
