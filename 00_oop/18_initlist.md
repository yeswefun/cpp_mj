


初始化列表

    特点
        一种便捷的初始化成员变量的方式
        只能用在构造函数中
        初始化顺序只跟成员变量的声明顺序有关


一种便捷的初始化成员变量的方式

```cpp
struct Person {
	int m_age;
	int m_height;
	/*
		push        20h
		push        10h
		lea         ecx,[p]
		call        Person::Person (03C1451h)

		mov         dword ptr [this],ecx

		mov         eax,dword ptr [this]
		mov         ecx,dword ptr [age]
		mov         dword ptr [eax],ecx

		mov         eax,dword ptr [this]
		mov         ecx,dword ptr [height]
		mov         dword ptr [eax+4],ecx
	*/
	Person(int age, int height) {
		m_age = age;
		m_height = height;
	}
};

int main() {
	Person p(16, 32);
}
```


```cpp
struct Person {
	int m_age;
	int m_height;

	Person(int age, int height) : m_age(age), m_height(height) {}
};
/*
    push        20h  
    push        10h  
    lea         ecx,[p]  
    call        Person::Person (0A11451h)

    mov         dword ptr [this],ecx
 
    mov         eax,dword ptr [this]
    mov         ecx,dword ptr [age]  
    mov         dword ptr [eax],ecx 
 
    mov         eax,dword ptr [this]  
    mov         ecx,dword ptr [height]  
    mov         dword ptr [eax+4],ecx
*/
int main() {
	Person p(16, 32);
}
```



初始化顺序只跟成员变量的声明顺序有关

```cpp
int init_age() {
	cout << "age" << endl;
	return 0;
}

int init_height() {
	cout << "height" << endl;
	return 0;
}
```

```cpp
struct Demo {
	int m_age;
	int m_height;

	Demo() : m_age(init_age()), m_height(init_height()) {}
};

/*
age
height
*/
int main() {
    Demo d;
    return 0;
}
```


```cpp
struct Demo {
    int m_height;
	int m_age;

	Demo() : m_age(init_age()), m_height(init_height()) {}
};

/*
height
age
*/
int main() {
    Demo d;
    return 0;
}
```



构造函数的互相调用


```cpp
struct Test {
	int m_age;
	int m_height;
/*
	Test() {
		m_age = 0;
		m_height = 0;
	}
*/
	Test() : Test(0, 0) {
		//this(0, 0); // error, java
		/*
        Test(0, 0); // error, 创建一个临时变量
			Test t;
			t.m_age = 0;
			t.m_height = 0;
		*/
	}

	Test(int age, int height) {
		m_age = age;
		m_height = height;
	}
};
```



初始化列表与默认参数配合使用

    如果函数声明和实现是分离的
        初始化列表只能写在函数的实现中
        默认参数只能写在函数的声明中


```cpp
struct User {
	int m_age;
	int m_height;

	User(int age = 0, int height = 0) : m_age(age), m_height(height) {}
};
```


```cpp
struct User {
	int m_age;
	int m_height;
	/*
		编译器在调用User函数之前，根据用户传入的参数个数，自动传入默认参数
            默认参数写在声明，方便编译器做语法检测
	*/
	User(int age = 0, int height = 0);
};

/*
	编译器生成User构造函数时，自动插入初始化列表中的代码
        参数列表写在实现
*/
User::User(int age, int height) : m_age(age), m_height(height) {}
```