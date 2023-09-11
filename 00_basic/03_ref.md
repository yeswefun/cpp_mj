


引用
    C的指针(Pointer)
    Cpp的引用(Reference)
        引用存在的价值之一：比指针更安全、函数返回值可以被赋值


```cpp
int id = 10;


// 指针的读写
int *p = &id;
*p = 20;
cout << *p << endl;


// 引用的读写
// 引用相当于是变量的别名
// 对引用做运算，就是对引用所指向的变量做运算
int &r = id;
r = 30;
cout << r << endl;
```


特点
    在定义的时候就必须初始化，一旦指向某个变量，就不可以再改变

    可以利用引用初始化另一个引用，相当于某个变量的多个别名

    引用相当于是变量的别名
        基本数据类型、枚举、结构体、类、指针、数组等，都可以有引用
        不存在 引用的引用、指向引用的指针、引用数组


```cpp
//int &r; // 引用必须初始化


int id = 10;
int &r = id;
int &s = r;
```





const
    被其修饰的变量不可修改
    如果修饰的是类、结构体（的指针），
        类，结构体(的指针)变量及其成员不可以修改


```cpp
//const int a; //const修饰的变量在定义时，必须初始化


const int c = 10;
//c = 20;


struct Date {
	int year;
	int month;
	int day;
};

const Date d = { 2022, 10, 30 };
Date d2 = { 2010, 11, 20};
//d.year = 2010;
//d = d2;


Date d3 = { 2022, 10, 30 };
Date d4 = { 2010, 11, 20 };
const Date *p = &d3;
//p->year = 2020;
//(*p).month = 11;
//(*p) = d4;
```



经典指针问题
    指针常量
    常量指针
    只读指针


```cpp
//以下5个指针分别是什么含义?
//const修饰的是其右边的内容

int id = 10;

//不能修改指针指向的变量
const int *p0 = &id;
int const *p1 = &id;

//不能修改指针指向
int * const p2 = &id;

//不能修改指针指向的变量
//不能修改指针指向
const int * const p3 = &id;
int const * const p4 = &id;
```
