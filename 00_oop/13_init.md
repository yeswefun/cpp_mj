

构造函数（Constructor）
    构造函数（也叫构造器），在对象创建的时候自动调用，一般用于完成对象的初始化工作

    特点
        函数名与类同名，无返回值（void都不能写），可以有参数，可以重载，可以有多个构造函数
        一旦自定义了构造函数，必须用其中一个自定义的构造函数来初始化对象


注意
    通过malloc分配的对象不会调用构造函数

```cpp
struct User {

	// 不会自动初始化，所以需要手动初始化
	int m_age;

	User() {
		m_age = 0;
		cout << "User(), age: " << m_age << endl;
	}

	~User() {
		cout << "~User(), age: " << m_age << endl;
	}
};

void test_init() {
	User *p = (User *)malloc(sizeof(User));
	free(p);

	User *p2 = new User;
	delete p2;
}
```


错误理解：默认情况下，编译器会为每一个类生成空的无参的构造函数
正确理解：在某些特定的情况下，编译器才会为类生成空的无参的构造函数
    虚函数时再补上

```cpp
struct Test {
	int m_age;
};

/*
    mov         dword ptr [t],0Ah
    并不会自动调用构造函数
*/
int main() {
	Test t;
	t.m_age = 10;
	return 0;
}
```


```cpp
struct Test {

	int m_age;

	Test() {
	}
};
/*
    lea         ecx,[t]  
    call        Test::Test (01514A6h)  
    mov         dword ptr [t],0Ah
*/
int main() {
	Test t;
	t.m_age = 10;	
	return 0;
}
```


```cpp
struct Test {
	
    int m_age = 0;

};
/*
    lea         ecx,[t]  
    call        Test::Test (0DA14A6h)
*/
int main() {
	Test t;	
	return 0;
}
```




构造函数的调用

```cpp
struct User {

	// 不会自动初始化，所以需要手动初始化
	int m_age;

	User() {
		m_age = 0;
		cout << "User(), age: " << m_age << endl;
	}

	~User() {
		cout << "~User(), age: " << m_age << endl;
	}
};

User g_u1;		// User()
User g_u2();	// 函数声明
User g_u3(10);  // User(int age)

int main() {
	User u1;	// User()
	User u2();	// 函数声明
	User u3(20);// User(int age)

	User *p1 = new User;	// User()
	User *p2 = new User();	// User()
	User *p3 = new User(30);// User(int age)

    return 0;
}
```



构造函数的调用 - 是否加上圆括号

```cpp
struct Test00 {
	int m_age;
};

struct Test01 {
	
	int m_age;

	//有影响
	Test01() {
	}
};
```


```cpp
// 结构体变量在全局区 - 初始化为0
Test00 g00;
Test01 g01;

Test00 *pa = new Test00;
Test00 *pb = new Test00();

Test01 *pc = new Test01;
Test01 *pd = new Test01();


void test_global() {
	cout << g00.m_age << endl;
    cout << g01.m_age << endl;

	cout << pa->m_age << endl; // 没有初始化
	cout << pb->m_age << endl;

	cout << pc->m_age << endl; // 没有初始化
	cout << pd->m_age << endl; // 没有初始化
    //存在无参构造时，就算加上圆括号，也不会对属性进行初始化
}
```


```cpp
void test_local() {
    
    // 结构体变量在栈区 - 不会初始化
    Test00 x;
    Test01 y;
    cout << x.m_age << endl; // 没有初始化
    cout << y.m_age << endl; // 没有初始化


	Test00 *pi = new Test00;
	Test00 *pj = new Test00();
	cout << pi->m_age << endl;  // 没有初始化
	cout << pj->m_age << endl;

	Test01 *pk = new Test01;
	Test01 *pl = new Test01();
	cout << pk->m_age << endl;  // 没有初始化
	cout << pl->m_age << endl;  // 没有初始化
}
```



成员变量的初始化

```cpp
Person() {
    memset(this, 0，sizeof(Person));
}
```
