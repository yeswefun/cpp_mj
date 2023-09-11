


static成员
	被static修饰的成员变量\函数

访问 static 成员
	对象（对象.静态成员）
	对象指针（对象指针->静态成员）
	类访问（类名::静态成员）



静态属性

```cpp
class Car {

public:
	static int id;
	//static int id = 0; // 不行

	int m_price;

	Car(int price) : m_price(price) {
		++Car::id;
	}

	void run() {
		cout << "run(), id: " << Car::id << ", price: " << m_price << endl;
	}
};

// 静态成员属性，类内定义，类外初始化，而且必须初始化
// Car内的静态成员
// 声明与实现分离，则初始化代码必须放到实现中
int Car::id = 0;

// 全局变量
//int id = 0;

int main() {

	Car c1(100);
	c1.run();

	Car c2(200);
	c2.run();

	cout << Car::id << endl;
	// c.id
	// p->id

	return 0;
}
```




静态函数

```cpp
class Car {

public:
	static int id;
	//static int id = 0; // 不行

	int m_price;

	Car(int price) : m_price(price) {
		++Car::id;
	}

	void run() {
		cout << "run(), id: " << Car::id << ", price: " << m_price << endl;
	}

	//virtual // 多态，父指针指向子类对象，涉及到对象
	static void showId() {
		//this的作用是用来访问外部变量
		//静态成员可以使用 类名::成员变量 来访问
		//m_price = 10;
		//this->m_price = 10;
		//run();
		//this->run();
		//static意味着编译器在调用函数时，不会传入this
		cout << "id: " << id << endl;
	}
};

// 静态成员属性，类内定义，类外初始化，而且必须初始化
// Car内的静态成员
// 声明与实现分离，则初始化代码必须放到实现中，而且实现部分不能带 static
//static int Car::id = 0;
int Car::id = 0;


/*
	静态只能访问静态
	动态可以访问静态和动态
*/
int main() {

	Car c(100);
	c.showId();

	Car *p = &c;
	p->showId();

	Car::showId();

	return 0;
}
```



```cpp
class Car {

public:
	static int id;

	int m_price;

	Car() {
		++Car::id;
	}
};

int Car::id = 0;

int id = 0;

int main() {

	Car c();

	/*
		41: 	c.m_price = 100;
		mov         dword ptr [ebp-0Ch],64h
		42: 	c.id = 2;
		mov         dword ptr ds:[00E78148h],2
		43: 	id = 1;
		mov         dword ptr ds:[00E7814Ch],1

		全局区 == 数据段 == dataSegment
	*/
	c.m_price = 100;
	c.id = 2;
	id = 1;

	return 0;
}
```




```cpp
class A {
public:
	static int id;
};

int A::id = 0;

class B : public A {
};

int main() {
	// 输出一样
	cout << &A::id << endl;
	cout << &B::id << endl;
	return 0;
}
```



```cpp
class A {
public:
	static int id;
};

int A::id = 0;

class B : public A {
public:
	static int id;
};

int B::id = 0;


int main() {
	// 输出不一样
	cout << &A::id << endl;
	cout << &B::id << endl;
	return 0;
}
```
