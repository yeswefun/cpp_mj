


重载(Overload)
    函数名相同
    参数列表不同
        类型
        个数
        顺序


    返回值类型不是函数重载的判断条件
```cpp
int test() {
	return 1;
}
double test() {
	return 3.14;
}

// 到底调用了哪个函数，歧义
test();
···



    调用函数时，实参的隐式类型转换可能会产生二义性
```cpp
/*
void test(int i) {
	cout << "test - int: " << i << endl;
}
*/
void test(long l) {
	cout << "test - long: " << l << endl;
}
void test(double d) {
	cout << "test - double: " << d << endl;
}

/*
10 可以隐式转换成 long 或 double
	long l = 10;
	double d = 10;
*/
test(10);
```



重载底层原理
    name mangling
        vs2015
            调试
                窗口
                    反汇编
	ida pro
	
    $ nm ./a.out



extern "C"
    在 C, C++ 混合开发时，
    函数声明文件中需要使用 extern "C"，函数实现文件需要包含函数声明文件

```cpp
#pragma once

//防止头文件被重复包含
#ifndef __DEMO_H
#define __DEMO_H


#ifdef __cplusplus
extern "C" {
#endif

// 函数声明

#ifdef __cplusplus
}
#endif


#endif //!__DEMO_H
```


#pragma once
    可以防止整个文件的内容被重复包含


#ifndef, #define, #endif
    可以按条件进行裁剪

