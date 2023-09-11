

默认参数

默认参数的值可以是常量、全局符号(全局变量、函数名)



如果函数同时有声明、实现，默认参数只能放在函数声明中

```cpp
void test(int x = 0, int y = 1, int z = 2);

void test(int x, int y, int z) {
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}
```



函数重载、默认参数可能会产生冲突、二义性（建议优先选择使用默认参数）

```cpp
//声明:
    test(int a, int b = 10);
    test(int a);

//调用:
     test(66);
```



默认参数的底层原理

```
test()
push        2  
push        1  
push        0  
call        test (03C1357h)  
add         esp,0Ch  

test(16);
push        2  
push        1  
push        10h  
call        test (03C1357h)  
add         esp,0Ch  

test(16, 32);
push        2  
push        20h  
push        10h  
call        test (03C1357h)  
add         esp,0Ch

test(16, 32, 48);
push        30h  
push        20h  
push        10h  
call        test (03C1357h)  
```