

C语言风格的类型转换符
	(type)expression
	type(expression)

C++中有4个类型转换符
	static_cast
	dynamic_cast
	reinterpret_cast
	const_cast

使用格式：xx_cast<type>(expression)


```cpp
int main() {

	int i = 10;
	double d = 3.14;

	// 隐式转换, implicit
	long l = i;
	double m = i;
	cout << l << endl;
	cout << m << endl;

	// 显式转换，explicit
	int j = (int)d;
	int k = int(d);
	cout << j << endl;
	cout << k << endl;

	return 0;
}
```


# const_cast

```cpp
class User {
};

int main() {

	const User *p1 = new User();

	//User *p2 = p1; // error

	// 让编译器不要做 const -> 非const 的语法检测
	// 汇编一样
	User *p2 = const_cast<User *>(p1);
	User *p3 = (User *)p1;

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	return 0;
}
```


# dynamic_cast

```cpp
class User {
	//添加虚函数，否则下面转换会报错
	virtual void test() {}
};

class Stud : public User {};

class Car {};

int main() {

	User *p1 = new User();
	User *p2 = new Stud();

	Stud *ps1 = dynamic_cast<Stud *>(p1); // not safe
	Stud *ps2 = dynamic_cast<Stud *>(p2); // safe

	Stud *ps11 = (Stud *)p1; // not safe
	Stud *ps22 = (Stud *)p2; // safe

	cout << "****************** p1" << endl;
	cout << p1 << endl;		// 0005F8A8
	cout << ps1 << endl;	// 00000000, NULL
	cout << ps11 << endl;	// 007E0FE8

	cout << "****************** p2" << endl;
	cout << p2 << endl;		// 0005FB48
	cout << ps2 << endl;	// 0005FB48
	cout << ps22 << endl;	// 0005FB48

	cout << "****************** car" << endl;
	Car *pc1 = (Car *)p1;
	Car *pc2 = dynamic_cast<Car *>(p2);
	cout << pc1 << endl;	// 00832CD0
	cout << pc2 << endl;	// 00000000, NULL

	return 0;
}
```


# static_cast

```cpp
class User {
	//添加虚函数，否则下面转换会报错
	virtual void test() {}
};

class Stud : public User {};

class Car {};

int main() {

	// 1. 缺乏运行时安全检测

	// 2. 不在同一个继承体系，不可以转换
	User *p1 = new User();
	User *p2 = new Stud();
	//Car *pc11 = static_cast<Car *>(p1);
	User *pc12 = static_cast<Stud *>(p2);
	User *pc13 = static_cast<Stud *>(p1);
	Car *pc10 = dynamic_cast<Car *>(p1);

	// 3. 基本数据类型的转换
	double d = 3.14;
	int a = static_cast<int>(d);
	int b = (int)d;
	cout << d << endl;
	cout << a << endl;
	cout << b << endl;

	// 4. 非const -> const
	User *px = new User();
	const User *py = px;
	const User *pz = static_cast<const User *>(px);
	cout << px << endl;
	cout << py << endl;
	cout << pz << endl;

	return 0;
}
```


# reinterpret_cast

```cpp
int main() {

	/*
		并不是简单地将 a 的4个字节拷贝到 b 的 8 个字节里面去
	*/
	// 0000 1010 0000 0000 0000 0000 0000 0000
	// 0A 00 00 00
	int a = 10;
	// 0A 00 00 00 00 00 00 00, 猜想
	// 00 00 00 00 00 00 24 40，实际
	double d = a;

	cout << d << endl;
	cout << a << endl;

	// 0A 00 00 00 cc cc cc cc
	// 不同类型之间的转换需要使用引用
	double e = reinterpret_cast<double&>(a);
	cout << e << endl;

	cout << sizeof(a) << endl;
	cout << sizeof(d) << endl;

	return 0;
}
```




```cpp
```

