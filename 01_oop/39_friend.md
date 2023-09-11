


友元
    友元函数
		非成员函数
			全局函数
		成员函数
    友元类


```cpp
class Point {
	int m_x;
	int m_y;
public:
	int getX() { return m_x; };
	int getY() { return m_y; };
	Point(int x, int y) : m_x(x), m_y(y) {}
	void display() {
		cout << "(" << m_x << ", " << m_y << ")" << endl;
	}
};

Point add(Point p1, Point p2) {
	return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}


int main() {
	Point p1(10, 20);
	Point p2(20, 30);
	
	Point p3 = add(p1, p2);
	p3.display();

	return 0;
}
```



全局函数作为友元函数

```cpp
class Point {
	friend Point add(Point p1, Point p2);
	int m_x;
	int m_y;
public:
	int getX() { return m_x; };
	int getY() { return m_y; };
	Point(int x, int y) : m_x(x), m_y(y) {}
	void display() {
		cout << "(" << m_x << ", " << m_y << ")" << endl;
	}
};

Point add(Point p1, Point p2) {
	return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}


int main() {
	Point p1(10, 20);
	Point p2(20, 30);
	
	Point p3 = add(p1, p2);
	p3.display();

	return 0;
}
```



友元类

```cpp
class Point {
	friend class Math;
	int m_x;
	int m_y;
public:
	int getX() { return m_x; };
	int getY() { return m_y; };
	Point(int x, int y) :m_x(x), m_y(y) {}
	void display() {
		cout << "(" << m_x << ", " << m_y << ")" << endl;
	}
};

class Math {
public:
	static Point add(Point p1, Point p2) {
		return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
	}

	void test() {
		Point p(10, 20);
		int x = p.m_x;
		p.m_x = 30;
	}
};


int main() {
	Point p1(10, 20);
	Point p2(20, 30);
	
	Point p3 = Math::add(p1, p2);
	p3.display();

	return 0;
}
```
