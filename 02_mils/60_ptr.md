


shared_ptr
    多个指针指向同一个对象

unique_ptr
    只能有一个指针指向同一个对象


```cpp
class A {

};


int main() {

	unique_ptr<A> p0;
	{
		unique_ptr<A> p1(new A());
		// 将 p1 中的内存地址转移支 p0 中
		p0 = move(p1);

		//unique_ptr<A> p2 = p1;
		//unique_ptr<A> p2(p1);
	}

	return 0;
}
```

