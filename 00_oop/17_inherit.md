


继承
    可以让子类拥有父类的所有成员（变量\函数）


```cpp
/*
struct Apple {
	int m_count;
	double m_price;
	double calc() {
		return m_count * m_price;
	}
};

struct Banana {
	int m_count;
	double m_price;
	double calc() {
		return m_count * m_price;
	}
};
*/

struct Fruit {
	int m_count;
	double m_price;
	void calc() {
		cout << (m_count * m_price) << endl;
	}
};
struct Apple : Fruit {
};

struct Banana : Fruit {
};

int main() {

	Apple a;
	a.m_count = 2;
	a.m_price = 3.0;
	a.calc();

	Banana b;
	b.m_count = 3;
	b.m_price = 4.0;
	b.calc();

	return 0;
}
```


父类的成员变量在前，子类的成员变量在后

```cpp
struct A {
	int m_a;
};

struct B : A {
	int m_b;
};

struct C : B {
	int m_c;
};

int main() {

	C c;
	cout << sizeof(A) << endl; // 4
	cout << sizeof(B) << endl; // 8
	cout << sizeof(C) << endl; // 12

	cout << &c.m_a << endl; // 00B8F880
	cout << &c.m_b << endl; // 00B8F884
	cout << &c.m_c << endl; // 00B8F888

	return 0;
}
```


成员访问权限、继承方式有3种
	public: 公共的，任何地方都可以访问(struct默认)
	protected: 子类内部、当前类内部可以访问
	private: 私有的，只有当前类内部可以访问(class默认)

    访问权限不影响对象的内存布局

     开发中用的最多的继承方式是public，
     这样能保留父类原来的成员访问权限

```cpp
class Fruit {}
class Apple : Fruit {}
class Apple : private Fruit {}

struct Fruit {}
struct Banana : Fruit {}
struct Banana : public Fruit {}
```


