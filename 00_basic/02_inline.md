

内联函数
    使用inline修饰函数的声明或者实现，可以使其变成内联函数
    建议声明和实现都增加inline修饰


特点
    编译器会将函数调用直接展开为函数体代码
    可以减少函数调用的开销
    会增大代码体积


函数调用的开销
	开辟栈空间
	回收栈空间


注意
    尽量不要内联超过10行代码的函数
    有些函数即使声明为inline，也不一定会被编译器内联，比如递归函数


```cpp
void test() {
	cout << "test()" << endl;
}

inline int add(int x, int y) {
	return x + y;
}
```


```
test();
call        test (0DE1090h)

int c = add(1, 2);
push        2  
push        1  
call        add (0DE10C0h)  
add         esp,8  
mov         dword ptr [c],eax
```


```
test();
call        std::operator<<<std::char_traits<char> > (09A1370h)

int c = add(1, 2);
mov         ecx,1
add         ecx,2
mov         dword ptr [c],ecx
```


vs2015 - Release
	禁用优化
		为了查看不加 inline 的函数
	内联函数扩展 - 默认 -> 任何适用项
		为了查看加 inline 的函数





内联函数和宏

    内联函数和宏，都可以减少函数调用的开销
    对比宏，内联函数多了语法检测和函数特性


```cpp
#define sum(x) (x + x)

inline int sum(int x) { return x + x; }

// 下面代码的执行结果
int a = 10;
sum(a++);
```


