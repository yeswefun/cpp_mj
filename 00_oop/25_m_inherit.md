



同名成员函数

```cpp
struct G {
	void test() {
		cout << "G::test()" << endl;
	}
};

struct H {
	void test() {
		cout << "H::test()" << endl;
	}
};

struct I : G, H {
	void test() {
		cout << "I::test()" << endl;
	}
};

int main() {
	
	I i;
	i.test();
    i.I::test();
	i.G::test();
	i.H::test();

	return 0;
}

/*
struct I : G, H {};

如果 I 中没有 test，那么 i 在调用 test 时，必须明确指定作用域
    i.G::test();
    i.H::test();
*/
```



同名成员变量

```cpp
struct J {
	int x;
};

struct K {
	int x;
};

struct L : J, K {
	int x;
};

int main() {

	L l;
	l.x = 15;
	l.L::x = l.x + 1;
	l.J::x = 32;
	l.K::x = 48;

	cout << l.x << endl;
	cout << l.L::x << endl;
	cout << l.J::x << endl;
	cout << l.K::x << endl;

	return 0;
}
```



菱形继承

    菱形继承带来的问题
        最底下子类从基类继承的成员变量冗余、重复
        最底下子类无法访问基类的成员，有二义性


```cpp
struct A {
	int m_a;
};

struct AB : A {
	//int m_a;
	int m_b;
};

struct AC : A {
	//int m_a;
	int m_c;
};

struct D : AB, AC {
	//int m_a;
	//int m_b;
	//int m_a;
	//int m_c;
	int m_d;
};


int main() {

	cout << sizeof(D) << endl; // 20

	// 调试 / 窗口 / 内存
	D d;
	d.AB::m_a = 1;
	d.m_b = 2;
	d.AC::m_a = 3;
	d.m_c = 4;
	d.m_d = 5;
	// d.m_a = 6; // m_a 必须指定作用域

	return 0;
}
```


虚继承
    虚继承可以解决菱形继承带来的问题
    A类被称为虚基类

```cpp
struct A {
	int m_a = 1;
	/*
	虚继承的好处: 虚基类成员变量越多，越能体现
	int m_a1 = 1;
	int m_a2 = 1;
	...
	*/
};

struct AB : virtual A {
	int m_b = 2;
};

struct AC : virtual A {
	int m_c = 3;
};

struct D : AB, AC {
	int m_d = 4;
};


int main() {

	cout << sizeof(D) << endl; // 24

	// 调试 / 窗口 / 内存
	D d;
	d.m_a = 16;

	return 0;
}
/*
0x004FF748  dc 6b 9c 00，本类中AB类对象的虚表地址：0x009c6bdc
0x004FF74C  02 00 00 00

0x004FF750  e4 6b 9c 00，本类中AC类对象的虚表地址：0x009c6be4
0x004FF754  03 00 00 00

0x004FF758  04 00 00 00，本类成员变量

0x004FF75C  01 00 00 00，虚基类中的成员变量


本类中AB类对象的虚表地址：0x009c6bdc
0x009C6BDC 00 00 00 00
0x009C6BE0 14 00 00 00

本类中AC类对象的虚表地址：0x009c6be4
0x009C6BE4  00 00 00 00
0x009C6BE8  0c 00 00 00
*/
```
