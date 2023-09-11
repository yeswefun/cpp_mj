



```cpp
class Test {
	static int count;
public:
	Test() {
		cout << "count: " << ++Test::count << endl;
	}
    ~Test() {
		cout << "count: " << --Test::count << endl;
	}
	/*
		不加static, t.getCount();	// 传入this
		加static, Test::getCount();	// 不传入this
	*/
	static int getCount() {
		return count;
	}
};

int Test::count = 0;

// 全局区
Test t1;

int main() {

    // 栈区
	Test t2;

    // 堆区
	Test *p = new Test();

	return 0;
}
```




```cpp
class Test {

};

/*
单例设计模式
	保证程序运行过程中只创建一个对象
*/
int main() {

	Test t1;
	Test t2;
	Test t3;

	cout << &t1 << endl;
	cout << &t2 << endl;
	cout << &t3 << endl;

	return 0;
}
```



```cpp
class Test {
private:
	//为什么要用指针?
	static Test* mInstance;
	Test() {}
	Test(const Test &t) {} // fix
	~Test() {}
	void operator=(const Test &t) {} // fix
public:
	static Test* getInstance() {
		// 此处需要考虑线程安全
		if (mInstance == NULL) {
			mInstance = new Test();
		}
		return mInstance;
	}
	static void deleteTest() {
		// 此处需要考虑线程安全
		if (mInstance != NULL) {
			delete mInstance;
			mInstance = NULL;
		}
	}
	void test() {
		cout << this << endl;
	}
};

Test* Test::mInstance = NULL;


/*
单例设计模式
	保证程序运行过程中只创建一个对象
*/
int main() {

	//私有化构造
	//Test *t1 = new Test();
	//Test *t2 = new Test();
	//Test *t3 = new Test();

	Test *t1 = Test::getInstance();
	Test *t2 = Test::getInstance();
	Test *t3 = Test::getInstance();

	t1->test();
	t2->test();
	t3->test();

	Test::deleteTest();
	Test *t4 = Test::getInstance();
	t4->test();

	//delete t4; // 私有化析构


	//*t1 = *t2; // 私有化 operator=

	//Test *t4 = new Test(*t1); // 私有化拷贝构造

	return 0;
}
```
