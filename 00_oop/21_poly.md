



虚函数
    C++中的多态通过虚函数（virtual function）来实现
    
    虚函数：被virtual修饰的成员函数
    
    只要在父类中声明为虚函数，子类中重写的函数也自动变成虚函数
    （也就是说子类中可以省略virtual关键字）


    虚函数的实现原理是虚表，
        这个虚表里面存储着最终需要调用的虚函数地址，
        这个虚表也叫虚函数表


    所有的Dog对象（不管在全局区、栈、堆）共用同一份虚表



```cpp
struct Animal {

	int m_age;

	//virtual 
	void voice() {
		cout << "Animal::voice()" << endl;
	}
	//virtual 
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

/*
x86: 32bit, 4byte
	Animal 没有 virtual, 4
	Animal 有 virtual, 8
x64: 64bit, 8byte
	Animal 没有 virtual, 4
	Animal 有 virtual, 16, (内存对齐)
*/
void test_size() {
	cout << sizeof(Dog) << endl;
}
```




```cpp
struct Animal {

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
虚表中函数地址的顺序与父类中虚函数的声明顺序有关
*/
int main() {
	/*
	111: 	Animal *p = new Dog();
	mov         dword ptr [ebp-0DCh],0
	mov         edx,dword ptr [ebp-0DCh]
	mov         dword ptr [p],edx

	112: 	p->voice();
	// 取出 p 内存中的前四个字节(Dog对象地址) 放到 eax
	mov         eax,dword ptr [p]
	// 取出 Dog对象地址的前四个字节(虚表地址) 放到 edx
	mov         edx,dword ptr [eax]
	// 取出 p 内存中的前四个字节(Dog对象地址) 放到 ecx, 调用函数之前，先传入参数
	mov         ecx,dword ptr [p]
	// 取出 虚表地址的前四个字节(成员函数voice的地址) 放到 eax
	mov         eax,dword ptr [edx]
	// 调用 成员函数 voice
	call        eax

	113: 	p->run();
	// 取出 p 内存中的前四个字节(Dog对象地址) 放到 eax
	mov         eax,dword ptr [p]
	// 取出 Dog对象地址的前四个字节(虚表地址) 放到 edx
	mov         edx,dword ptr [eax]
	// 取出 p 内存中的前四个字节(Dog对象地址) 放到 ecx, 调用函数之前，先传入参数
	mov         ecx,dword ptr [p]
	// 取出 虚表地址+四个字节(成员函数run的地址) 放到 eax
	mov         eax,dword ptr [edx+4]
	// 调用 成员函数 run
	call        eax
	*/
	Animal *p = new Dog();
	p->voice();	// 编译器在编译该语句时，只知道 p 是 Animal 类型的指针
	p->run();	// 将函数地址与具体类型对象绑定在一起，运行时，就知道该调用哪个函数

	/*
		p 中的地址值 是 Dog对象的地址值
		调试 / 窗口 / 内存
		
		Dog对象的地址

		虚表地址(Dog对象的地址的前四个字节)
		34 9b 2e 01 00，小端模式
			低位存低字节，高位存高字节
			0x00012e9b34
				虚表地址中存放的内容
				0x012E9B34  e2 14 2e 01，0x012e14e2
				0x012E9B38  c9 14 2e 01，0x012e14c9
	*/
	return 0;
}
```


所有的Dog对象（不管在全局区、栈、堆）共用同一份虚表

```cpp
int main() {

	Animal *p = new Cat();
	p->m_age = 16;
	p->voice();
	p->run();

	Animal *p2 = new Cat();
	p2->voice();
	p2->run();
	
	return 0;
}
```


虚表中存放的函数地址个数等于基类中的 virtual 的个数

```cpp
struct Animal { // 没有

	int m_age;

	void voice() {};
 
	void run() {};
};

struct Animal { // 一个

	int m_age;

	virtual 
	void voice() {};
 
	void run() {};
};

struct Animal { // 两个

	int m_age;

	virtual 
	void voice() {};

	virtual 
	void run() {};
};
```
