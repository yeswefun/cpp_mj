


调用父类的成员函数实现

```cpp
struct A {
    virtual void test() {
        cout << "A::test()" << endl;
    }
}

struct B {
    void test() {
        cout << "B::test() start" << endl;
        A::test();
        cout << "B::test() stop" << endl;
    }
}
```



虚析构函数
    含有虚函数的类，应该将析构函数声明为虚函数（虚析构函数）
    delete父类指针时，才会调用子类的析构函数，保证析构的完整性

```cpp
struct Animal {
	Animal() {
		cout << "Animal()" << endl;
	}
	virtual ~Animal() {
		cout << "~Animal()" << endl;
	}
};
struct Dog : Animal {
	Dog() {
		cout << "Dog()" << endl;
	}
	~Dog() {
		cout << "~Dog()" << endl;
	}
};

void test00() {
	/*
		父类指针指向子类对象

			没有虚表
				Animal()
				Dog()
				~Animal()

			有虚表
				Animal()
				Dog()
				~Dog()
				~Animal()
	*/
	Animal *p = new Dog();
	delete p;
}
```


纯虚函数:没有函数体且初始化为0的虚函数，用来定义接口规范
	java中的抽象类

    抽象类(Abstract Class)
        含有纯虚函数的类，不可以实例化(不可以创建对象)
        抽象类也可以包含非纯虚函数、成员变量
        如果父类是抽象类，子类没有完全重写纯虚函数，那么这个子类依然是抽象类

```cpp
// 抽象类
struct A {
	// 纯虚函数 - 父类中的实现没有意义
	virtual void demo00() = 0;
};

// 具体类
struct B : A {
	void demo00() {
		cout << "demo - B" << endl;
	}
};

// 抽象类
struct C : A {

};
```

