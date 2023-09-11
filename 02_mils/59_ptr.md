

```cpp
class Person {
public:
	int m_age;
	Person() {
		cout << "Person()" << endl;
	}
	Person(int age) : m_age(age) {
		cout << "Person(int)" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
	void run() {
		cout << "run() - " << m_age << endl;
	}
};
```



```cpp
int main() {

	cout << 1 << endl;

	{
		shared_ptr<Person> p(new Person(10));	// 单个
		//shared_ptr<Person[]> p(new Person[3]);	// 数组
	}

	cout << 2 << endl;

	return 0;
}
```




```cpp
int main() {

	cout << "********************* 1" << endl;

	{
		shared_ptr<Person> p4;
		{
			shared_ptr<Person> p1(new Person(10));
			cout << p1.use_count() << endl;

			shared_ptr<Person> p2 = p1;
			cout << p1.use_count() << endl;

			shared_ptr<Person> p3 = p2;
			cout << p1.use_count() << endl;

			p4 = p3;
			cout << p1.use_count() << endl;
		}

        cout << p4.use_count() << endl;

		cout << "********************* 2" << endl;
	}

	cout << "********************* 3" << endl;

	return 0;
}
```





```cpp
class User;

class Car {
public:
	User *m_user;
};

class User {
public:
	Car *m_car;
};

int main() {

	return 0;
}
```


```cpp
class User;

class Car {
public:
	shared_ptr<User> m_user;
	Car() {
		cout << "Car()" << endl;
	}
	~Car() {
		cout << "~Car()" << endl;
	}
};

class User {
public:
	shared_ptr<Car> m_car;
	User() {
		cout << "User()" << endl;
	}
	~User() {
		cout << "~User()" << endl;
	}
};

int main() {

	{
		shared_ptr<User> u(new User());
		shared_ptr<Car> c(new Car());

		//下面两行(循环引用)导致对象无法被回收
		//u->m_car = c;
		//c->m_user = u;
	}

	return 0;
}
```


```cpp
class User;

class Car {
public:
	weak_ptr<User> m_user;
	Car() {
		cout << "Car()" << endl;
	}
	~Car() {
		cout << "~Car()" << endl;
	}
};

class User {
public:
	weak_ptr<Car> m_car;
	User() {
		cout << "User()" << endl;
	}
	~User() {
		cout << "~User()" << endl;
	}
};

int main() {

	{
		shared_ptr<User> u(new User());
		shared_ptr<Car> c(new Car());

		//下面两行(循环引用)导致对象无法被回收
		//循环引用 仅针对 智能指针
		//u->m_car = c;
		//c->m_user = u;
	}

	return 0;
}
```
