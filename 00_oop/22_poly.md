

子类若没有重写基类中 virtual ，则虚表中会用基类中的函数地址进行填充

```cpp
struct Animal { // 两个

	int m_age;

	virtual 
	void voice() {};

	virtual
	void run() {};
};

struct Dog : Animal {
	void voice() {};
	void run() {};
};
/*
虚表中存放的内容
	Dog::voice
	Dog::run
*/
```



```cpp
struct Animal { // 两个

	int m_age;

	virtual 
	void voice() {};

	virtual
	void run() {};
};

struct Dog : Animal {
	void voice() {};
};
/*
虚表中存放的内容
	Dog::voice
	Animal::run
*/
```



```cpp
struct Animal { // 两个

	int m_age;

	virtual 
	void voice() {};

	virtual
	void run() {};
};

struct Dog : Animal {
};
/*
虚表中存放的内容
	Animal::voice
	Animal::run
*/
```



父类是否有虚表 - 有

```cpp
struct Animal { // 两个

	int m_age;

	virtual 
	void voice() {};

	virtual 
	void run() {};
};
int main() {

	Animal *p = new Animal();
	/*
		mov         eax,dword ptr [p]  
		mov         dword ptr [eax+4],1`0h
	*/
	p->m_age = 16;
	p->voice();
	p->run();
	return 0;
}
```


虚表中存放的内容
	Dog::voice
	Animal::run

```cpp
struct Animal {
	
	int m_age;

	virtual 
	void voice() {
		cout << "Animal::voice()" << endl;
	}
	virtual
	void run() {
		cout << "Animal::run()" << endl;
	}
};
struct Dog : Animal {
	void voice() {
		cout << "Dog::voice()" << endl;
	}
};
struct Bob : Dog {

};
```



调用结果
	Bob::voice
	Bob::run
	Bob::voice
	Bob::run

```cpp
struct Animal {
	
	int m_age;

	virtual
	void voice() {
		cout << "Animal::voice()" << endl;
	}
	virtual
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
struct Bob : Dog {
	void voice() {
		cout << "Bob::voice()" << endl;
	}
	void run() {
		cout << "Bob::run()" << endl;
	}
};

int main() {
	Animal *p0 = new Bob();
	p0->voice();
	p0->run();

	Dog *p1 = new Bob();
	p1->voice();
	p1->run();
	return 0;
}
```



调用结果
	Animal::voice
	Animal::run
	Bob::voice
	Bob::run

```cpp
struct Animal {
	
	int m_age;

	void voice() {
		cout << "Animal::voice()" << endl;
	}
	void run() {
		cout << "Animal::run()" << endl;
	}
};
struct Dog : Animal {
	virtual
	void voice() {
		cout << "Dog::voice()" << endl;
	}
	virtual
	void run() {
		cout << "Dog::run()" << endl;
	}
};
struct Bob : Dog {
	void voice() {
		cout << "Bob::voice()" << endl;
	}
	void run() {
		cout << "Bob::run()" << endl;
	}
};

int main() {
	Animal *p0 = new Bob();
	p0->voice();
	p0->run();

	Dog *p1 = new Bob();
	p1->voice();
	p1->run();
	return 0;
}
```
