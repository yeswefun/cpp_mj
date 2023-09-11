


auto_ptr
    c++ 11 不推荐使用
	不支持数组

shared_ptr
    c++ 11

unique_ptr
    c++ 11



```cpp
void test() {
	throw 666;
}

int main() {

	try {

		int *p = new int();

		void test();

		delete p;

	} catch (...) {

	}

	return 0;
}
```



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
void test() {
	//Person *p = new Person();
	//delete p;
	
	//智能指针底层原理: 
	//栈对象持有堆对象地址，栈对象释放时会自动调用析构函数，
	//此时可以在栈对象的析构函数中释放堆对象的内存
	auto_ptr<Person> p(new Person(10));
	p->run();
}
```




```cpp
int main() {

	cout << 1 << endl;

	{
		auto_ptr<Person> p(new Person(10));
		p->run();
	}

	cout << 2 << endl;

	return 0;
}
```



```cpp
int main() {

	cout << 1 << endl;

	{
		Person person(10); // 栈上对象自动析构
		auto_ptr<Person> p(&person);
		p->run();
	}

	cout << 2 << endl;

	return 0;
}
```



```cpp
template <typename T>
class SmartPtr {
private:
	T *m_ptr;
public:
	SmartPtr(T *ptr) : m_ptr(ptr) {}
	~SmartPtr() {
		if (m_ptr == nullptr)
			return;
		delete m_ptr;
		m_ptr = nullptr;
	}
	T* operator->() {
		return m_ptr;
	}
};

int main() {

	cout << 1 << endl;

	{
		SmartPtr<Person> p(new Person(10));
		//p->->run();
		p->run();
	}

	cout << 2 << endl;

	return 0;
}
```
