

vftable: Virtual Function Table
	虚函数表


C++的编译器在某些特定的情况下，会给类自动生成无参的构造函数，比如
	
	成员变量在声明的同时进行了初始化

	继承
		有定义虚函数

		虚继承其他类

		父类有无参构造函数（编译器生成或自定义）

	组合
		包含对象类型的成员，且这个成员有无参构造函数（编译器生成或自定义）

	总结一下
		对象创建后，需要做一些额外操作时（比如内存操作、函数调用），
		编译器一般都会为其自动生成无参的构造函数

		创建完对象之后，是否还有其它事情要做



成员变量在声明的同时进行了初始化

```cpp
class Car {
public:
	int m_price;
};

int main() {
    // 没有调用无参构造
	Car c;
	return 0;
}
```



```cpp
class Car {
public:
	int m_price = 16;
};

/*
class Car {
public:
	int m_price;
    Car() {
        m_price = 16;
    }
};
*/

int main() {
    // 调用了无参构造
	Car c;
	return 0;
}
```



类中有无参构造函数(编译器生成或自定义)

```cpp
class Car {
public:

};

int main() {
    // 没有调用无参构造
	Car c;
	return 0;
}
```



```cpp
class Car {
public:
	Car() {
	}
};

int main() {
    // 调用了无参构造
	Car c;
	return 0;
}
```



父类有无参构造函数(编译器生成或自定义)

```cpp
class Car {
public:

};

class BigCar : public Car {

};

int main() {
    // 没有调用无参构造
	BigCar c;
	return 0;
}
```


```cpp
class Car {
public:
	Car() {

	}
};

class BigCar : public Car {

};

int main() {
    // 调用了无参构造
	BigCar c;
	return 0;
}
```



有定义虚函数

```cpp
class Car {
public:
	void run() {
	}
};

int main() {
    // 没有调用无参构造
	Car c;
	return 0;
}
```



```cpp
class Car {
public:
    /*
        有 virtual 就意味着有虚表，
        当 Car 对象创建完成之后，它要给虚表赋值
    */
	virtual void run() {
	}
};

int main() {
    // 调用了无参构造
	Car c;
	return 0;
}
```



虚继承其他类

```cpp
class Car {
public:
	int m_price;
};

class BigCar : public Car {

};

int main() {
    // 没有调用无参构造
	BigCar c;
	return 0;
}
```



```cpp
class Car {
public:
	int m_price;
};

/*
BigCar对象创建完成之后，它要给虚表赋值，自动调用父类构造
*/
class BigCar : virtual public Car {

};

int main() {
    // 调用了无参构造
	BigCar c;
	return 0;
}
```



包含对象类型的成员，且这个成员有构造函数(编译器生成或自定义)

```cpp
class Car {
public:
	int m_price;
};

class User {
public:
	Car car;
};

int main() {
    // 没有调用无参构造
	User u;
	return 0;
}
```



```cpp
class Car {
public:
	int m_price;
	Car() {

	}
};

class User {
public:
	Car car;
};

int main() {
    // 调用了无参构造
	User u;
	return 0;
}
```



```cpp
class Car {
public:
	int m_price = 0;
};

class User {
public:
	Car car;
};

int main() {
    // 调用了无参构造
	User u;
	return 0;
}
```
