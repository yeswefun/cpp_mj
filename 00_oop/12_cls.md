

封装
    成员变量私有化，提供公共的getter和setter给外界去访问成员变量

```cpp
struct User {

private:
	int m_id;

public:
	int getId() {
		return m_id;
	}
	void setId(int id) {
		if (id < 0) {
			return;
		}
		m_id = id;
	}
	void show() {
		cout << "id = " << m_id << endl;
	}
};

void test_encasulation() {
	User u;
	//u.m_id = 6;
	u.show();
	u.setId(-1);
	u.show();
}
```



内存空间的布局
    每个应用都有自己独立的内存空间，其内存空间一般都有以下几大区域

```
代码段（代码区）
    用于存放代码

数据段（全局区）
    用于存放全局变量等

栈空间
    每调用一个函数就会给它分配一段连续的栈空间，等函数调用完毕后会自动回收这段栈空间
    自动分配和回收

堆空间
    需要手动去申请和释放
```

```cpp
int main() {
    // 栈上指针变量指向堆内存首地址
    User *p = new User();
    return 0;
}
```



堆空间
    在程序运行过程，为了能够自由控制内存的生命周期、大小，会经常使用堆空间的内存

    堆空间的申请\释放
        malloc \ free
        new \ delete
        new [] \ delete []

    注意
        申请堆空间成功后，会返回那一段内存空间的首地址
        申请和释放必须是1对1的关系，不然可能会存在内存泄露

        现在的很多高级编程语言不需要开发人员去管理内存（比如Java），
        屏蔽了很多内存细节，利弊同时存在
            利：提高开发效率，避免内存使用不当或泄露
            弊：不利于开发人员了解本质，永远停留在API调用和表层语法糖，对性能优化无从下手

```cpp
void test_malloc() {
	// void* 万能指针
	char *pc = (char *)malloc(sizeof(char));
	int *pi = (int *)malloc(sizeof(int));
	free(pc);
	free(pi);
}

void test_new() {
	char *pc = new char;
	int *pi = new int;
	delete pc;
	delete pi;

	char *px = new char[4];
	delete[] px;
}
```


堆内存初始化
    memset函数是将较大的数据结构(比如对象、数组等)内存清零的比较快的方法

    memset函数
        将较大的数据结构(比如对象、数组等)内存清零的比较快的方法
        
        Person p;
        memset(&p, 0, sizeof(p)); // sizeof(p) == 一个结构体的字节大小

        Person p[3];
        memset(&p, 0, sizeof(p)); // sizeof(p) == 所有结构体的字节大小


```cpp
int *p1 = (int * )malloc(sizeof(int)); // *p1未初始化
int *p2 = (int * )malloc(sizeof(int));
memset(p2, 0，sizeof(int));             // 将*p2的每-个字节都初始化为0
```


```cpp
int *p1 = new int;          //未被初始化
int *p2 = new int();        //被初始化为0
int *p3 = new int(5);       //被初始化为5
int *p4 = new int[3];       //数组元素未被初始化
int *p5 = new int[3]();     //3个数组元素都被初始化为0
int *p6 = new int[3]{};     //3个数组元素都被初始化为0
int *p7 = new int[3]{5};    //数组首元素被初始化为5，其他元素被初始化为0
```


```cpp
/*
memset(p, 0, size);
从 p 开始 到 p+size 结束 的每个字节设置为 0

memset(p, 1, size);
从 p 开始 到 p+size 结束 的每个字节设置为 1 (每个字节，正确理解)
从 p 开始 到 p+size 结束 设置为 1 (整个内存，错误理解)
*/
void test_init_mem() {
	int *p = (int *)malloc(sizeof(int));
	memset(p, 0, sizeof(int));  // *p = 0; // 只能设置单个
	cout << *p << endl;
	free(p);

	int size = sizeof(int) * 3;
	int *px = (int *)malloc(size);
	memset(px, 0, size);
	free(px);
}

void test_init_mem2() {
	int *p0 = new int;
	int *p1 = new int();
	int *p2 = new int(6);
	cout << *p0 << endl;	// -842150451
	cout << *p1 << endl;	// 0
	cout << *p2 << endl;	// 6
	delete p0;
	delete p1;
	delete p2;
}
```



对象的内存
    对象的内存可以存在于3种地方
        全局区（数据段）：全局变量
        栈空间：函数里面的局部变量
        堆空间：动态申请内存（malloc、new等）

```cpp
//全局区
Person g_ person;

int main( ) {
    //栈空间
    Person person;

    //堆空间
    Person *p = new Person;

    return 0;
}
```
