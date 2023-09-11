



```cpp
int main() {

	cout << 1 << endl;

	try {
		cout << "1 / 0, 1" << endl;
        // 并没有抛出异常，运算前需要对参与运行的操作数进行检查
		int x = 1 / 0;
		cout << "1 / 0, 2" << endl;
	} catch (...) {
		cout << "error occur" << endl;
	}

	cout << 2 << endl;

	return 0;
}
```





```cpp
namespace A {
	int div(int a, int b) {
		if (b == 0)
			throw "divided by zero";
		return a / b;
	}
}

int main() {

	cout << 1 << endl;

	try {
		cout << "1 / 0, 1" << endl;
		A::div(1, 0);
		cout << "1 / 0, 2" << endl;
	} catch (const char *msg) {
		cout << msg << endl;
	} catch (...) {
		cout << "error occur" << endl;
	}

	cout << 2 << endl;

	return 0;
}
```





```cpp
void test00() {
	cout << "test00, 1" << endl;
	throw 666;
	cout << "test00, 2" << endl;
}

void test01() {
	cout << "test01, 1" << endl;
	try {
		test00();
	} catch (int n) {
		cout << "error: " << n << endl;
	}
	cout << "test01, 2" << endl;
}

int main() {

	cout << "main, 1" << endl;
	test01();
	cout << "main, 2" << endl;

	return 0;
}
```




```cpp
class Exception {
public:
	virtual const char *what() const = 0;
};

class DivException : public Exception {
public:
	const char* what() const {
		return "divided by zero";
	}
};

class AddException : public Exception {
public:
	const char* what() const {
		return "failed to add";
	}
};


namespace A {
	int div(int a, int b) {
		if (b == 0)
			throw DivException();
		return a / b;
	}
}

int main() {

	cout << "main, 1" << endl;
	try {
		cout << "1 / 0, 1" << endl;
		A::div(1, 0);
		cout << "1 / 0, 2" << endl;
	} catch (DivException &e) {
		cout << e.what() << endl;
	} catch (const Exception &e) {
        // const 是为了接收 const 与 非const
        // & 是为了避免 拷贝构造
		cout << e.what() << endl;
	}
	cout << "main, 2" << endl;

	return 0;
}
```
