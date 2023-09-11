

this
    this是指向当前对象的指针

    对象在调用成员函数的时候，会自动传入当前对象的内存地址


```cpp
struct Person {

	int m_id;

	/*
		不同对象访问同一份代码，怎么区分当前对象?
		mov         dword ptr [ebp-0Ch],6

		lea         ecx,[ebp-0Ch]
		call        013B1357

		mov         dword ptr [ebp-8],ecx
		mov         eax,dword ptr [ebp-8]
		mov         dword ptr [eax],6

		函数在代码区，对象在 栈 或 堆
			p.run(&p); 
			this指针存储着函数调用者的地址
			void run(Person *p) {
				cout << "Person::run(), id = " << p->m_id << endl;
			}
	*/
	void run() {
		//this->m_id = 6;
		m_id = 6;
	}
};


void test_person() {
	Person p1;
	p1.m_id = 6;
	p1.run();

	Person p2;
	p2.m_id = 8;
	p2.run();
}
```



```cpp
struct User {
	int m_id;
	int m_age;
	int m_height;

	/*
        mov         dword ptr [ebp-14h],1
        mov         dword ptr [ebp-10h],2
        mov         dword ptr [ebp-0Ch],3

        lea         ecx,[ebp-14h]
        call        0130141F

        mov         dword ptr [ebp-8],ecx
        
        mov         eax,dword ptr [ebp-8]
        mov         dword ptr [eax],10h
        
        mov         eax,dword ptr [ebp-8]
        mov         dword ptr [eax+4],20h
        
        mov         eax,dword ptr [ebp-8]
        mov         dword ptr [eax+8],30h
	*/
	void change() {
		m_id = 16;
		m_age = 32;
		m_height = 48;
	}

	void display() {
		cout << m_id << ", " << m_age << ", " << m_height << endl;
	}
};

void test_user00() {
	User u;
	u.m_id = 1;
	u.m_age = 2;
	u.m_height = 3;
	u.change();
}

void test_user01() {
	/*
        mov         dword ptr [ebp-14h],1
        mov         dword ptr [ebp-10h],2
        mov         dword ptr [ebp-0Ch],3

        lea         eax,[ebp-14h]
        mov         dword ptr [ebp-20h],eax

        mov         eax,dword ptr [ebp-20h]
        mov         dword ptr [eax],10h

        mov         eax,dword ptr [ebp-20h]
        mov         dword ptr [eax+4],20h

        mov         eax,dword ptr [ebp-20h]
        mov         dword ptr [eax+8],30h
	*/
	User u;
	u.m_id = 1;
	u.m_age = 2;
	u.m_height = 3;

    /*
        可以利用this.m_age来访问成员变量么?
            不可以，因为this是指针，必须用this->m_age
    */
	User *p = &u;
	p->m_id = 16;
	p->m_age = 32;
	p->m_height = 48;
}
```


指针访问对象成员的本质

```cpp
struct User {
	int m_id;
	int m_age;
	int m_height;

	void change() {
		m_id = 16;
		m_age = 32;
		m_height = 48;
	}

	void display() {
		cout << m_id << ", " << m_age << ", " << m_height << endl;
	}
};


/*
原理:如何利用指针间接访问所指向对象的成员变量?
	1.从指针中取出对象的地址
	2.利用 对象的地址+成员变量的偏移量 计算出成员变量的首地址
	3.根据成员变量的首地址访问成员变量的存储空间

代码区的内容是不可以修改的
临时变量在栈区
*/
int main() {
	
	User u;
	u.m_id = 1;
	u.m_age = 2;
	u.m_height = 3;
	u.display();

	User *p = (User *)&u.m_age;
	p->m_id = 16;
	p->m_age = 32;
	
    // 1，16，32
    u.display();    // 将 u 对象的地址值传入display作为参数
	
    // 16, 32, -858993460
    // 输出会有问题，因为 this 指针的偏移不对
	//p->display(); // 将 p 内存中的 地址值(age的地址值)传入display作为参数

	return 0;
}
```
