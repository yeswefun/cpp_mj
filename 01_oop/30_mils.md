



new & delete

```cpp
int *p = new int();

delete p;
// p != NULL
```


const
	const成员：被const修饰的成员变量、非静态成员函数

```cpp
class Car {
public:
	// 所有对象共享同一份
	//static const int m_price = 0;

	// 每个对象都有一份
	//const int m_price = 0; // 初始化方式一

	const int m_price; // 初始化方式一
	Car() : m_price(0) {}

	//static void show() const {} // error
	void show() {
		cout << "m_price: " << m_price << endl;
	}
};

int main() {

	Car car;

	return 0;
}
```



非const对象（指针）优先调用非const成员函数

const成员函数（非静态）
	const关键字写在参数列表后面，函数的声明和实现都必须带const


```cpp
class Test {
public:
	int m_price;
	void test() const;

	//const成员函数和非const成员函数构成重载
	void test() {
		cout << "test()" << endl;
	}
};

void Test::test() const {
	cout << "test() const" << endl;
	//m_price = 0; // error，内部不能修改非static成员变量
	//只能调用 const 成员函数， static 成员函数
	//非const成员函数可以调用 const 成员函数
}

int main() {

	Test t1;
	t1.test();

	const Test t2;
	t2.test();

	Test *p1 = new Test();
	p1->test();

	const Test *p2 = new Test();
	p2->test();

	return 0;
}
```



```cpp
class Test {
public:
	int m_price;

	void test() {
		cout << "test()" << endl;
	}
};

int main() {

	Test t1;
	t1.test();

	const Test t2;
	//t2.test(); // error

	return 0;
}
```




```cpp
class Test {
public:
	int m_price;
	void test() const;
};

void Test::test() const {
	cout << "test() const" << endl;
}

int main() {

	Test t1;
	t1.test();

	const Test t2;
	t2.test();

	return 0;
}
```
