

父类的构造函数
    子类的构造函数默认会调用父类的无参构造函数
    
    如果子类的构造函数显式地调用了父类的有参构造函数，
    就不会再去默认调用父类的无参构造函数
    
    如果父类缺少无参构造函数，子类的构造函数必须显式调用父类的有参构造函数



子类的构造函数默认会调用父类的无参构造函数

```cpp
struct A {
	A() {
		cout << "A()" << endl;
	}
};

struct B : A {
	B() {
		cout << "B()" << endl;
	}
};
```


如果子类的构造函数显式地调用了父类的有参构造函数，
就不会再去默认调用父类的无参构造函数

```cpp
struct C {
	C() {
		cout << "C()" << endl;
	}
	C(int id) {
		cout << "C(int id)" << endl;
	}
};

struct D : C {
	D() : C(10) {
		cout << "D()" << endl;
	}
};
```



如果父类缺少无参构造函数，子类的构造函数必须显式调用父类的有参构造函数

```cpp
struct E {
	E(int id) {
		cout << "E(int id)" << endl;
	}
};

struct F : E {
	F() : E(10) {
		cout << "F()" << endl;
	}
};
```




继承体系下的构造函数示例

```cpp
struct G {
	G(int id) {
		cout << "G(int id)" << endl;
	}
};

struct H : G {
	
	int m_age;

	H(int id, int age) : G(id), m_age(age) {

	}
};
```




```cpp
struct Person {
    
    int m_ age;
    
    Person() :Person(0) {
    }
    Person(int age) :m_ age(age) {
    }
};

struct Student : Person {
    
    int m_ no;
    
    Student() :Student(0, 0) {
    }
    Student(int age, int no) :Person(age), m_ no(no) {
    }
};
```




构造、析构顺序
    构造和析构顺序相反

```cpp
struct I {
	I() {
		cout << "I()" << endl;
	}
	~I() {
		cout << "~I()" << endl;
	}
};

struct J : I {
	J() {
		// call I::I
		cout << "J()" << endl;
	}
	~J() {
		cout << "~J()" << endl;
		// call I::~I
	}
};

/*
    I()
    J()
    ~J()
    ~I()
*/
int main() {
	{
		J j;
	}
	return 0;
}
```

