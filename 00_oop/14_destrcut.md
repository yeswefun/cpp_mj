


析构函数（Destructor）
    析构函数（也叫析构器），在对象销毁的时候自动调用，一般用于完成对象的清理工作
    
    特点
        函数名以~开头，与类同名，无返回值（void都不能写），无参，不可以重载，有且只有一个析构函数

    注意
        通过malloc分配的对象free的时候不会调用构造函数
        构造函数、析构函数要声明为public，才能被外界正常使用


```cpp
struct User{
	User() {
		cout << "User()" << endl;
	}

	~User() {
		cout << "~User()" << endl;
	}
};

void test_destruct() {
	User u;
}

void test00() {
	{
		User u;
	}
	test_destruct();
}
```



```cpp
struct Car {

	int m_price;

	Car() {
		m_price = 0;
		cout << "Car()" << endl;
	}

	~Car() {
		cout << "~Car()" << endl;
	}
};

struct Person {

	int m_age;
	Car *m_car;

	// 初始化工作
	Person() {
		cout << "Person()" << endl;
		m_age = 0;
		m_car = new Car();
	}

	// 内存清理工作
	~Person() {
		if (m_car != NULL) {
			delete m_car;
		}
		cout << "~Person()" << endl;
	}
};

/*
    内存泄露:该释放的内存并没有得到释放

    对象内部申请的堆空间，由对象内部回收
*/
int main() {
	{
		Person p;
	}
	return 0;
}
```


