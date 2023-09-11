

常引用（Const Reference）
    引用可以被const修饰，这样就无法通过引用修改数据

```cpp
/*
	常引用 和 常指针
*/
void test_const() {
	//常引用，无法通过引用去修改，但可以使用原变量进行修改
	int id = 10;
	const int &r = id;
	const int *p = &id;

	//r = 20;
	//*p = 20;

	id = 30;
	cout << r << endl;
}


void test_pointer(const int *p) {
	//*p = 20;
}

void test_reference(const int &r) {
	//r = 20;
}
```



const必须写在&符号的左边，才能算是常引用

```cpp
	int id = 10;
	
	// r不可以改变指向，也不可以通过 r 修改其指向的变量
	const int &r = id;
	int const &r2 = id;
	//r = 20;
	id = 30;

	// r3不可以改变指向，可以通过 r 修改其指向的变量
	int & const r3 = id; // 相当于什么也没有做
	r3 = 20; // 这并不是改变 r3 的指向，而是给 r3 指向的变量赋值
	id = 50;

	// 引用变量在定义时必须初始化，且不能再改变其指向
```



const引用的特点
    可以指向临时数据（常量、表达式、函数返回值等）

```cpp
int ret() {
	return 6;
}

/*
const引用的特点
	可以指向临时数据(常量、表达式、函数返回值等)
*/
void test_tmp() {
	// 只能引用变量，引用本质是指向，应该指向变量地址
	//int &r = 10;
	const int &r = 10;

	//int &r2 = 10 + 20;
	const int &r2 = 10 + 20;

	//int &r3 = ret();
	const int &r3 = ret();
}
```


```cpp
/*
可以指向不同类型的数据
    当常引用指向了不同类型的数据时，会产生临时变量
    即引用指向的并不是初始化时的那个变量
*/
void test_diff_type() {
	/*
        mov         dword ptr [ebp-0Ch],0Ah

        mov         eax,dword ptr [ebp-0Ch]
        mov         dword ptr [ebp-24h],eax
        lea         ecx,[ebp-24h]
        mov         dword ptr [ebp-18h],ecx

        mov         dword ptr [ebp-0Ch],14h
	*/
	int id = 10;
	const long &r = id;
	//int tmp = id;
	//const long &r = tmp;
	id = 20;
	/*
		id: 20
		r: 10
	*/
	cout << "id: " << id << endl;
	cout << "r: " << r << endl;
}

void test_same_type() {
	int id = 10;
	const int &r = id;
	//r = 20;
	id = 20;
	cout << "id: " << id << endl;
	cout << "r: " << r << endl;
}
```



```cpp
/*
作为函数参数时(此规则也适用于const指针)
	可以接受const和非const实参(非const引用，只能接受非const实参)
	可以跟非const引用构成重载
*/
int add(int &x, int &y) {
	return x + y;
}

int add(const int &x, const int &y) {
	return x + y;
}

int sum(int &x, int &y) {
	return x + y;
}

void test_const_arg() {
	int x = 10;
	int y = 20;

	const int c = 10;
	const int d = 20;

	add(x, y);
	add(c, d);
	add(10, 20);

	sum(x, y);
	//sum(c, d);	// err
	//sum(10, 20);  // err
}
```



数组引用

```cpp
int arr = {16, 32, 48};

int (&r)[3] = arr;

int * const &s = arr;
```




不存在的引用变量

```cpp
void test_not_exist() {

	int id = 10;
	int &r = id;

	//不存在引用的引用
	//int &&r2 = r; // r == id

	// 不存在指向引用的指针
	//int &*r2 = &r; // r == id

	// 不存在引用数组
	//int &arr[3] = {r, r, r}; // r == id
}
```




引用的本质就是指针
	只是编译器削弱了它的功能，所以引用就是弱化了的指针
	一个引用占用一个指针的大小


```cpp
	int id = 10;
	cout << "sizeof(id): " << sizeof(id) << endl;

	// *p 是 id 的别名
	int *p = &id;
	*p = 20;
	cout << "sizeof(p): " << sizeof(p) << endl;

	// r 是 id 的别名
	int &r = id;
	r = 30;
	cout << "sizeof(r): " << sizeof(r) << endl;

	cout << "sizeof(&p): " << sizeof(&p) << endl;
	cout << "sizeof(&r): " << sizeof(&r) << endl;
	cout << "sizeof(&id): " << sizeof(&id) << endl;
```


```
138: 	// *p 是 id 的别名
139: 	int *p = &id;
lea         eax,[ebp-0Ch]
mov         dword ptr [ebp-18h],eax
140: 	*p = 20;
mov         eax,dword ptr [ebp-18h]
mov         dword ptr [eax],14h

143: 	// r 是 id 的别名
144: 	int &r = id;
lea         eax,[ebp-0Ch]
mov         dword ptr [ebp-24h],eax
145: 	r = 30;
mov         eax,dword ptr [ebp-24h]
mov         dword ptr [eax],1Eh
```





指针大小
	x86: 32bit, 4byte
	x64: 64bit, 8byte

调试模式下才有反汇编
	去掉显示符号名
	去掉显示地址值
	x86

```cpp
struct Stud0 {
	int id;
};
struct Stud1 {
	int &id;
};

cout << "sizeof(Stud0): " << sizeof(Stud0) << endl;
cout << "sizeof(Stud1): " << sizeof(Stud1) << endl;
```




左值，右值

```cpp
int a = 1;
int b = 2;

(a = b) = 3;

(a > b ? a : b) = 4;
```
