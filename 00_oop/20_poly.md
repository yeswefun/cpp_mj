

面向对象
	封装
	继承
	多态


野指针: 指向非法内存的指针
空指针: 指向 NULL 的指针


重载(overload)与重写(override)
	重载
		同一个类中
		方法名相同，参数列表不同
	重写
		父子类中
		方法签名一致


父类指针、子类指针

    父类指针可以指向子类对象，是安全的
        开发中经常用到（继承方式必须是public）

    子类指针指向父类对象是不安全的


```cpp
struct Person {
	int m_age;
};

struct Stud : Person {
	int m_score;
};

void test00() {
	//父类指针指向子类对象
	Person *p = new Stud();
	p->m_age = 16;

	Stud *p2 = (Stud *) new Person(); // not safe
	p2->m_age = 32;
	//p2->m_score = 16
	//cout << p2->m_score << endl;
}
```



多态
	默认情况下，编译器只会根据指针类型调用对应的函数，不存在多态

	多态是面向对象非常重要的一个特性
		同一操作作用于不同的对象，可以有不同的解释，产生不同的执行结果
		在运行时，可以识别出真正的对象类型，调用对应子类中的函数

	多态的要素
		子类重写父类的成员(虚)函数(override)
		父类指针指向子类对象
		利用父类指针调用重写的成员函数


```cpp
struct Animal {
	void voice() {
		cout << "Animal::voice()" << endl;
	}
	void run() {
		cout << "Animal::run()" << endl;
	}
};

struct Dog : Animal {
	void voice() {
		cout << "Dog::voice()" << endl;
	}
	void run() {
		cout << "Dog::run()" << endl;
	}
};
struct Cat : Animal {
	void voice() {
		cout << "Cat::voice()" << endl;
	}
	void run() {
		cout << "Cat::run()" << endl;
	}
};
```


方式一

```cpp
void walk(Dog *p) {
	p->voice();
	p->run();
}

void walk(Cat *p) {
	p->voice();
	p->run();
}

void test01() {
	walk(new Dog());
	walk(new Cat());
}
```


方式二，默认情况下，编译器只会根据指针类型调用对应的函数，不存在多态

```cpp
void walk(Animal *p) {
	p->voice();
	p->run();
}

void test02() {
	walk(new Dog());
	walk(new Cat());
}
```




多态实现

```cpp
/*
虚函数
	C++中的多态通过虚函数(virtual function) 来实现
	虚函数:被virtual修饰的成员函数
		父类中声明虚函数
		子类重写虚函数，子类中的 virtual 可以不写
*/
struct Animal {
	virtual void voice() {
		cout << "Animal::voice()" << endl;
	}
	virtual void run() {
		cout << "Animal::run()" << endl;
	}
};

struct Dog : Animal {
	void voice() {
		cout << "Dog::voice()" << endl;
	}
	void run() {
		cout << "Dog::run()" << endl;
	}
};
struct Cat : Animal {
	void voice() {
		cout << "Cat::voice()" << endl;
	}
	void run() {
		cout << "Cat::run()" << endl;
	}
};

void walk(Animal *p) {
	p->voice();
	p->run();
}

void test02() {
	walk(new Dog());
	walk(new Cat());
}
```
