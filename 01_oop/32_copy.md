



```cpp
class Car {
public:
	int m_price;
	int m_length;

	Car(int price = 0, int length = 0) : m_price(price), m_length(length) {
		cout << "Car(int price = 0, int length = 0)" << endl;
	}

	Car(const Car &car) : m_price(car.m_price), m_length(car.m_length) {
		cout << "Car(const Car &car)" << endl;
		//this->m_price = car.m_price;
		//this->m_length = car.m_length;
	}

	void display() {
		cout << "price = " << m_price << ", length = " << m_length << endl;
	}
};


int main() {

	Car c1;
	Car c2(100);
	Car c3(100, 200);

	// 利用已经存在的 Car 对象创建一个新的 Car 对象
	// c4初始化时会调用拷贝构造函数
	Car c4(c3);
	//Car c4 = c3; // 隐式
	//c4.m_price = c3.m_price;
	//c4.m_length = c4.m_length;
	//x86 -> x64, assembly
	c4.display();

	return 0;
}
```




调用父类的拷贝构造

```cpp
class Person {
public:
	int m_age;
	Person(int age = 0) :m_age(age) {}
	Person(const Person &person) :m_age(person.m_age) {}
};
class Student : public Person {
public:
	int m_score;
	Student(int age = 0, int score = 0) :Person(age), m_score(score) {}
	Student(const Student &student) :Person(student), m_score(student.m_score) {}
};


int main() {

	Student stud1(18, 100);
	Student stud2(stud1);

	cout << stud2.m_age << endl;
	cout << stud2.m_score << endl;

	return 0;
}
```



```cpp
// 调用父类的拷贝构造
class Person {
public:
	int m_age;
	Person(int age = 0) :m_age(age) {}
	//Person(const Person &person) :m_age(person.m_age) {}
};
class Student : public Person {
public:
	int m_score;
	Student(int age = 0, int score = 0) :Person(age), m_score(score) {}
	//Student(const Student &student) :Person(student), m_score(student.m_score) {}
};

int main() {

	Student stud1(18, 100);
	Student stud2(stud1);

	cout << stud2.m_age << endl;
	cout << stud2.m_score << endl;

	return 0;
}
```



```cpp
// 调用父类的拷贝构造
class Person {
public:
	int m_age;
	//Person();		// m_age = 0;
	//Person(age);	// m_age = age;
	Person(int age = 0) :m_age(age) {}
	//Person(const Person &person) :m_age(person.m_age) {}
};
class Student : public Person {
public:
	int m_score;
	Student(int age = 0, int score = 0) : m_score(score) {}
	//Student(const Student &student) :Person(student), m_score(student.m_score) {}
};

int main() {

	Student stud1(18, 100);
	Student stud2(stud1);

	cout << stud2.m_age << endl; // 为什么不是 0xcc, 子类构造会自动调用父类无参构造
	cout << stud2.m_score << endl;

	return 0;
}
```




```cpp
class Car {
public:
	int m_price;
	int m_length;

	Car(int price = 0, int length = 0) : m_price(price), m_length(length) {
		cout << "Car(int price = 0, int length = 0)" << endl;
	}

	Car(const Car &car) : m_price(car.m_price), m_length(car.m_length) {
		cout << "Car(const Car &car)" << endl;
	}
};

/*
拷贝构造是在初始化时才会调用
*/
int main() {
	/*
		创建了四个对象
	*/
	Car c1(100, 5);

	Car c2(c1);
	Car c3 = c2;

	Car c4;

	// 下面并不是创建对象，而是指向同一个对象
	c4 = c3; // 没有调用拷贝构造函数，值拷贝
	c4.display();
	return 0;
}
```

