


隐式构造
	寻找只有一个参数且类型为 X 的构造
	类型 o = X;

```cpp
class Car {
	int m_price;
public:
	Car() {
		cout << "Car(): " << this << endl;
	}
	Car(int price) : m_price(price) {
		cout << "Car(int): " << this << endl;
	}
	Car(const Car &car) {
		cout << "Car(const Car &): " << this << endl;
	}
	~Car() {
		cout << "~Car(): " << this << endl;
	}
	void run() {
		cout << "run(), price = " << m_price << endl;
	}
};
```



```cpp
int main() {

	Car c1;
	
	Car c2(10);
	Car c20 = 10;	// 寻找只有一个参数，且类型为int的构造

	Car c3(c2);
	Car c30 = c2;	// 寻找只有一个参数，且类型为Car的构造
	
	return 0;
}
```



```cpp
void test00(Car c) {
}

/*
Car(int): 0095FBF4
*/
int main() {
	test00(10);
	return 0;
}
```



```cpp
Car test01() {
	return 30;
}

/*
Car(int): 0075FA30
*/
int main() {
	Car c = test01();
	return 0;
}
```



```cpp
/*
Car(): 006FFECC
Car(int): 006FFE00
*/
int main() {
	Car c;
	c = 20;
	return 0;
}
```


```cpp
/*
Car(int): 008FFCF4
*/
int main() {
	Car c = 20;
	return 0;
}
```


可以通过关键字explicit禁止掉隐式构造

```cpp
class Car {
public:
	explicit Car(int price) : m_price(price) {
		cout << "Car(int): " << this << endl;
	}
}
```
