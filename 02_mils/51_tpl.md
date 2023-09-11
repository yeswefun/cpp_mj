


```cpp
class Array {
	int *m_data;
	int m_size;
	int m_capacity;
public:
	Array(int capacity) {
		m_capacity = capacity > 0 ? capacity : 4;
		m_data = new int[m_capacity];
	}
	~Array() {
		if (m_data == NULL)
			return;
		delete[] m_data;
		m_data = NULL;
	}

	void add(int value) {
		if (m_size == m_capacity) {
			/*
				动态扩容
					1. 申请一块更大的堆内存
					2. 将旧堆内存中的数据拷贝到新堆内存
					3. 释放掉旧堆内存
			*/
			cout << "capacity not enough" << endl;
			return;
		}
		m_data[m_size++] = value;
	}

	int& get(int index) {
		if (index < 0 || index >= m_size) {
			throw "index out of bound";
		}
		return m_data[index];
	}

	int size() {
		return m_size;
	}

	int& operator[](int index) {
		return get(index);
	}
};

/*
Array arr = new Array();
arr[0] = 1;
int x = arr[0];

长度固定，无法动态扩容
int arr[] = { 1, 2, 3 };
*/
int main() {

	Array arr(4);

	cout << "****************** size" << endl;
	cout << arr.size() << endl;
	arr.add(10);
	cout << arr.size() << endl;
	arr.add(20);
	cout << arr.size() << endl;
	arr.add(30);
	arr.add(40);
	arr.add(50);

	cout << "****************** get" << endl;
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;

	cout << "****************** []" << endl;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;

	cout << "****************** [] - fix" << endl;
	arr[0] = 6;
	cout << arr[0] << endl;

	return 0;
}
```




```cpp
template <typename T>
class Array {
	T *m_data;
	int m_size;
	int m_capacity;
public:
	Array(int capacity) {
		m_capacity = capacity > 0 ? capacity : 4;
		m_data = new T[m_capacity];
	}
	~Array() {
		if (m_data == NULL)
			return;
		delete[] m_data;
		m_data = NULL;
	}

	void add(T value) {
		if (m_size == m_capacity) {
			/*
			动态扩容
			1. 申请一块更大的堆内存
			2. 将旧堆内存中的数据拷贝到新堆内存
			3. 释放掉旧堆内存
			*/
			cout << "capacity not enough" << endl;
			return;
		}
		m_data[m_size++] = value;
	}

	T get(int index) {
		if (index < 0 || index >= m_size) {
			throw "index out of bound";
		}
		return m_data[index];
	}

	int size() {
		return m_size;
	}

	T operator[](int index) {
		return get(index);
	}
};

/*
Array arr = new Array();
arr[0] = 1;
int x = arr[0];

长度固定，无法动态扩容
int arr[] = { 1, 2, 3 };
*/
int main() {

	Array<int> arr(4);

	cout << "****************** size" << endl;
	cout << arr.size() << endl;
	arr.add(10);
	cout << arr.size() << endl;
	arr.add(20);
	cout << arr.size() << endl;
	arr.add(30);
	arr.add(40);
	arr.add(50);

	cout << "****************** get" << endl;
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;

	cout << "****************** []" << endl;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;

	//cout << "****************** [] - fix" << endl;
	//arr[0] = 6;
	//cout << arr[0] << endl;


	cout << "****************** double" << endl;
	Array<double> arr2(4);
	arr2.add(3.14);
	arr2.add(2.718);
	arr2.add(0.618);
	cout << arr2[0] << endl;
	cout << arr2[1] << endl;
	cout << arr2[2] << endl;

	return 0;
}
```



