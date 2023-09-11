



```cpp
struct A {
	int m_a;
	void method_a() {
		cout << "method_a, m_a: " << m_a << endl;
	}
};

struct B {
	int m_b;
	void method_b() {
		cout << "method_b, m_b: " << m_b << endl;
	}
};

/*
struct C : public A, private B {}
继承顺序决定成员变量在内存存储的先后顺序
*/
struct C : A, B {
	int m_c;
	void method_c() {
		cout << "method_c, m_c: " << m_c << endl;
	}
};

int main() {

	C c;
	c.m_a = 1;
	c.m_b = 2;
	c.m_c = 3;
	c.method_a();
	c.method_b();
	c.method_c();

	// 12
	cout << sizeof(c) << endl;

	return 0;
}
```






```cpp
struct A {
	int m_a;
	A(int a) : m_a(a) {}
	void method_a() {
		cout << "method_a, m_a: " << m_a << endl;
	}
};

struct B {
	int m_b;
	B(int b) : m_b(b) {}
	void method_b() {
		cout << "method_b, m_b: " << m_b << endl;
	}
};

/*
struct C : public A, private B {}
继承顺序决定成员变量在内存存储的先后顺序
*/
struct C : A, B {
	int m_c;
	C(int a, int b, int c) : A(a), B(b), m_c(c) {}
	void method_c() {
		cout << "method_c, m_c: " << m_c << endl;
	}
};

int main() {

	C c(1, 2, 3);
	c.method_a();
	c.method_b();
	c.method_c();

	// 12
	cout << sizeof(c) << endl;

	return 0;
}
```


多继承-虚函数
	如果子类继承的多个父类都有虚函数，
	那么子类对象就会产生对应的多张虚表

```cpp
struct D {
	virtual void method_d() {
		cout << "D::method_d" << endl;
	}
};

struct E {
	virtual void method_e() {
		cout << "D::method_e" << endl;
	}
};

struct F : D, E {
	int m_id;
	void method_d() {
		cout << "F::method_d" << endl;
	}
	void method_e() {
		cout << "F::method_e" << endl;
	}
};

int main() {
	
	/*
		F::method_d
		F::method_e
	*/
	D *pd = new F();
	E *pe = new F();
	pd->method_d();
	pe->method_e();

	F *pf = new F();
	pf->m_id = 1;

	return 0;
}
```
