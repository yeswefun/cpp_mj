




```cpp
#pragma once

#include <iostream>
using namespace std;


template <typename T>
class Array {
	//friend ostream& operator<<<>(ostream& cout, const Array<T> &arr);
	template <typename T>
	friend ostream& operator<<(ostream& cout, const Array<T> &arr);

	T *m_data;
	int m_size;
	int m_capacity;
public:
	Array(int capacity);
	~Array();

	void add(T value);

	T get(int index);

	int size();

	T operator[](int index);

	void rmeove(int index);
	void insert(int index, T value);
};


template <typename T>
Array<T>::Array(int capacity) {
	m_capacity = capacity > 0 ? capacity : 4;
	m_data = new T[m_capacity];
}

template <typename T>
Array<T>::~Array() {
	if (m_data == NULL)
		return;
	delete[] m_data;
	m_data = NULL;
}

template <typename T>
void Array<T>::add(T value) {
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

template <typename T>
T Array<T>::get(int index) {
	if (index < 0 || index >= m_size) {
		throw "index out of bound";
	}
	return m_data[index];
}

template <typename T>
int Array<T>::size() {
	return m_size;
}

template <typename T>
T Array<T>::operator[](int index) {
	return get(index);
}


template <typename T>
ostream& operator<<(ostream& cout, const Array<T> &arr) {
	cout << "[";
	for (int x = 0; x < arr.m_size; x++) {
		if (x != 0) {
			cout << ", ";
		}
		cout << arr.m_data[x];
	}
	return cout << "]";
}

template <typename T>
void Array<T>::rmeove(int index) {
	if (index < 0 || index >= m_size) {
		throw "index out of bound";
	}
	for (int x = index+1; x < m_size; x++) {
		m_data[x-1] = m_data[x];
	}
	--m_size;
}

template <typename T>
void Array<T>::insert(int index, T value) {
	// index check
	for (int x = size; x > index; x--) {
		m_data[x] = m_data[x-1];
	}
	m_data[index] = value;
	++m_size;
}
```



```cpp
#include "array.hpp"

class Point {
	friend ostream& operator<<(ostream &cout, const Point &p);

	int m_x;
	int m_y;
public:
	Point() : Point(0, 0) {}
	Point(int x, int y) : m_x(x), m_y(y) {}
	//Point(int x = 0, int y = 0) : m_x(x), m_y(y) {}
};

ostream& operator<<(ostream &cout, const Point &p) {
	return cout << "(" << p.m_x << ", " << p.m_y << ")";
}

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
	cout << arr << endl;

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
	cout << arr2 << endl;

	
	cout << "****************** double" << endl;
	Array<Point> arr3(4);
	arr3.add(Point(1, 2));
	arr3.add(Point(3, 4));
	arr3.add(Point(5, 6));
	arr3.add(Point(7, 8));
	cout << arr3[0] << endl;
	cout << arr3 << endl;

	return 0;
}
```
