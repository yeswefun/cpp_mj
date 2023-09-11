

内部类

```cpp
class Person {

private:
	int m_age;

	void test() {
		Car c;
		//c.m_price = 10;
	}

	static int m_id;

	static void demo() {}

public:
	class Car {
	private:
		int m_price;
	public:
		void run() {
			Person p;
			p.m_age = 10;
		}
		void fly() {
			Person::m_id = 10;
			Person::demo();

			m_id = 20;
			demo();
		}
	};
};

int main() {

	Person::Car car1;
	Person::Car car2;

	return 0;
}
```



局部类

```cpp
void test() {
	class Car {
		// 类内定义，类外初始化
		//static int m_price;
	};
	//int Car::m_price = 10;
}
```
