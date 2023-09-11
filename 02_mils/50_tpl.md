


模板没有被使用时，是不会被实例化出来的

模板的声明和实现如果分离到.h和.cpp中，会导致链接错误

一般将模板的声明和实现统一放到一个.hpp文件中



```cpp
int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}

class Point {
	friend ostream& operator<<(ostream &cout, const Point &p);

	int m_x;
	int m_y;
public:
	Point(int x, int y) : m_x(x), m_y(y) {}

	Point operator+(const Point &p) {
		return Point(m_x + p.m_x, m_y + p.m_y);
	}
};

Point add(Point a, Point b) {
	return a + b;
}

ostream& operator<<(ostream &cout, const Point &p) {
	return cout << "(" << p.m_x << ", " << p.m_y << ")";
}

int main() {

	cout << add(0, 1) << endl;
	cout << add(2.718, 3.14) << endl;
	cout << add(Point(1, 2), Point(3, 4)) << endl;

	return 0;
}
```



```cpp
class Point {
	friend ostream& operator<<(ostream &cout, const Point &p);

	int m_x;
	int m_y;
public:
	Point(int x, int y) : m_x(x), m_y(y) {}

	Point operator+(const Point &p) {
		return Point(m_x + p.m_x, m_y + p.m_y);
	}
};

ostream& operator<<(ostream &cout, const Point &p) {
	return cout << "(" << p.m_x << ", " << p.m_y << ")";
}

template <typename T>
T add(T a, T b) {
	return a + b;
}

/*
	Cpp模板原理: 编译时生成相应的函数
*/
int main() {

	cout << add<int>(0, 1) << endl;
	cout << add(0, 1) << endl;

	cout << add<double>(2.718, 3.14) << endl;
	cout << add(2.718, 3.14) << endl;

	cout << add<Point>(Point(1, 2), Point(3, 4)) << endl;
	cout << add(Point(1, 2), Point(3, 4)) << endl;

	return 0;
}
```


```cpp
template <typename P1, typename P2, typename R>
R test(P1 a, P2 b) {
	return a + b;
}
int main() {
	cout << test<int, double, Point>(1, 3.14) << endl;
	return 0;
}
```







```cpp
#pragma once
int add(int a, int b);
double add(double a, double b);
```


```cpp
#include "add.h"

int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}
```


```cpp
#include "add.h"

int main() {
	cout << add(0, 1) << endl;
	cout << add(2.718, 3.14) << endl;
	return 0;
}
```



链接错误
	先编译 main.cpp ，编译器可以从头文件中知道存在函数调用(此时先占位)
	编译器完成后生成 .o 文件，再进行链接，此时模板函数所在文件并没有存在函数，
	所以不会生成模板函数，链接失败


```cpp
#pragama once
template <typename T>
T add(T a, T b);
```

```cpp
template <typename T>
T add(T a, T b) {
	return a + b;
}
```

```cpp
#include "add.h"

int main() {
	cout << add(0, 1) << endl;
	cout << add(2.718, 3.14) << endl;
	return 0;
}
```




```cpp
// add.hpp
template <typename T>
T add(T a, T b) {
	return a + b;
}

```

```cpp
#include "add.hpp"

int main() {
	cout << add(0, 1) << endl;
	cout << add(2.718, 3.14) << endl;
	return 0;
}
```

