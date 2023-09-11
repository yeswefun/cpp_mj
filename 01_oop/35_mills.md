





```cpp
class Car {
public:
	Car() {
		cout << "Car(): " << this << endl;
	}
	Car(const Car &car) {
		cout << "Car(const Car &): " << this << endl;
	}
	void run() {
		cout << "run()" << endl;
	}
};
```


对象类型参数和返回值
	使用对象类型作为函数的参数或者返回值，可能会产生一些不必要的中间对象


有名对象作为参数

```cpp
// 在传入参数的过程产生临时对象
void test00(Car car) {
}

int main() {
	Car c1;
	test00(c1);
	return 0;
}
```



```cpp
void test00_fix(Car &car) { // const Car &car
}

int main() {
	Car c1;
	test00_fix(c1);
	return 0;
}
```



有名对象作为返回值

```cpp
// 函数返回的过程产生临时对象
Car test01() {
	Car c;
	return c;
}

/*
Car(): 00DDF8B3
Car(): 00DDF7BF
Car(const Car &): 00DDF7E7
*/
int main() {
	Car c;
    //main函数将变量地址传入，test00在函数结束之前给那块传入的地址赋值
	c = test01(); // 不会调用拷贝构造，operator=
	return 0;
}
```



```cpp
// 函数返回的过程产生临时对象
Car test01() {
	Car c;
	return c;
}

/*
Car(): 010FFBD7
Car(const Car &): 010FFCCB
*/
int main() {
    // 只做一次拷贝构造，编译器做了优化
	Car c = test01(); // 会调用拷贝构造，看汇编
	return 0;
}
```





匿名对象(临时对象)

```cpp
/*
1
Car(): 0055FB3B
~Car(): 0055FB3B
2
*/
int main() {
	cout << 1 << endl;
	Car();
	cout << 2 << endl;
	return 0;
}
```





临时对象作为参数

```cpp
void test00(Car car) {
}
/*
Car(): 00F3F883
Car(const Car &): 00F3F78C
*/
int main() {
	Car c;
	test00(c);
	return 0;
}
```


```cpp
void test00(Car car) {
}
/*
Car(): 009EF6BC
*/
int main() {
	test00(Car());
	return 0;
}
```




临时对象作为返回值

```cpp
Car test01() {
	Car c1;
	return c1;
}
/*
Car(): 001BF6CF
Car(const Car &): 001BF7CF
*/
int main() {
	Car c = test01();
	return 0;
}
```



```cpp
Car test02() {
	return Car();
}
/*
Car(): 00FDFE8F
*/
int main() {
	Car c = test02();
	return 0;
}
```


