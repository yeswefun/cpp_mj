



```cpp
int main() {

	const char *name = "bmw";
	char name2[] = { 'b', 'm', 'w', '\0' };
	char name3[] = { 'b', 'm', 'w', '\0', 'a', 'b' };
	
	cout << sizeof(name) << endl;	// 4
	cout << sizeof(name2) << endl;	// 4
	cout << sizeof(name3) << endl;	// 6

	cout << strlen(name) << endl;	// 3
	cout << strlen(name2) << endl;	// 3
	cout << strlen(name3) << endl;	// 3

	return 0;
}
```





深浅拷贝
	浅拷贝的问题
		可能会导致堆空间多次free的问题
	如果需要实现深拷贝（deep copy），就需要自定义拷贝构造函数
		将指针类型的成员变量所指向的内存空间，拷贝到新的内存空间

```cpp
class Car {
	int m_price;
	char *m_name;
public:
	Car(int price = 0, char *name = NULL) : m_price(price), m_name(name) {}
	void display() {
		cout << "price = " << m_price << ", name = " << m_name << endl;
	}
};

Car *g_car;
void test() {
	//const char *name = "bmw";
	char name[] = { 'b', 'm', 'w', '\0' };
	g_car = new Car(100, name);
}

/*
野指针: 指向非法内存地址的指针
*/
int main() {
	
	test();
	g_car->display();

	return 0;
}
```


malloc / free

```cpp
class Car {
	int m_price;
	char *m_name;
public:
	Car(int price = 0, const char *name = NULL) : m_price(price) {
		if (name == NULL)
			return;
		m_name = (char *)malloc(strlen(name) + 1);
		strcpy(m_name, name);
	}
	void display() {
		cout << "price = " << m_price << ", name = " << m_name << endl;
	}
	~Car() {
		if (m_name != NULL) {
			free(m_name);
			m_name = NULL;
		}
	}
};

Car *g_car;
void test() {
	//char *name = new char[4] { 'b', 'm', 'w', '\0' };
	//const char *name = "bmw";
	char name[] = { 'b', 'm', 'w', '\0' };
	g_car = new Car(100, name);
	//g_car = new Car(100, "bmw");
	//delete[] name;
}

/*
野指针: 指向非法内存地址的指针

To disable deprecation,
use _CRT_SECURE_NO_WARNINGS.See online help for details
属性 / C/C++ / 命令行 / -D "_CRT_SECURE_NO_WARNINGS"
*/
int main() {
	
	test();
	g_car->display();

	return 0;
}
```



new / delete


```cpp
class Car {
	int m_price;
	char *m_name;
public:
	Car(int price = 0, const char *name = NULL) : m_price(price) {
		if (name == NULL)
			return;
		m_name = new char[strlen(name) + 1]{};
		strcpy(m_name, name);
	}
	void display() {
		cout << "price = " << m_price << ", name = " << m_name << endl;
	}
	~Car() {
		if (m_name != NULL) {
			delete[] m_name;
			m_name = NULL;
		}
	}
};

Car *g_car;
void test() {
	//char *name = new char[4] { 'b', 'm', 'w', '\0' };
	//const char *name = "bmw";
	char name[] = { 'b', 'm', 'w', '\0' };
	g_car = new Car(100, name);
	//g_car = new Car(100, "bmw");
	//delete[] name;
}

/*
野指针: 指向非法内存地址的指针

To disable deprecation,
use _CRT_SECURE_NO_WARNINGS.See online help for details
属性 / C/C++ / 命令行 / -D "_CRT_SECURE_NO_WARNINGS"
*/
int main() {
	
	test();
	g_car->display();

	return 0;
}
```





```cpp
class Car {
	int m_price;
	char *m_name;
	void copy_name(const char *name) {
		if (name == NULL)
			return;
		m_name = new char[strlen(name) + 1]{};
		strcpy(m_name, name);
	}
public:
	Car(int price = 0, const char *name = NULL) : m_price(price) {
		if (name == NULL)
			return;
		m_name = new char[strlen(name) + 1]{};
		strcpy(m_name, name);
	}
/*
	Car(const Car& c) : m_price(c.m_price) {
		if (c.m_name == NULL)
			return;
		m_name = new char[strlen(c.m_name) + 1]{};
		strcpy(m_name, c.m_name);
	}
*/
	void display() {
		cout << "price = " << m_price << ", name = " << m_name << endl;
	}
	~Car() {
		if (m_name != NULL) {
			delete[] m_name;
			m_name = NULL;
		}
	}
};

int main() {
	
	Car c1(100, "bmw");
	Car c2 = c1; // Car c2(c1);
	c2.display();

	return 0;
}
```


