


汇编语言

    汇编语言的种类
        8086汇编（16bit）
        x86汇编（32bit）
        x64汇编（64bit）
        ARM汇编（嵌入式、移动设备）
        ...

    x64汇编根据编译器的不同，有2种书写格式
        Intel
        AT&T

    汇编语言不区分大小写


    学习汇编语言2大知识点:
        1.汇编指令
        2.寄存器


目标 - x64，Intel

|64..32 |31..16 |15..8  |7..0   |
                |AH     |AL     |
                |AX             |
        |EAX                    |
|RAX                            |


一般的规律
    R开头的寄存器是64bit的，占8字节
    E开头的寄存器是32bit的，占4字节



# mov dst src
    将 src 的内容赋值给 dst，类似于 src = dst

    [地址值]
        中括号[]里面放的都是内存地址
        [可以做简单运算]，如 [epb-0CH]

        word是2字节
        dword是4字节 (double word)
        qword是8字节(quad word)


```cpp
	/*
		mov         dword ptr [ebp-8],0Ah
		mov         dword ptr [ebp-14h],14h
		mov         eax,dword ptr [ebp-8]
		add         eax,dword ptr [ebp-14h]
		mov         dword ptr [ebp-20h],eax
	*/
	int a = 10;
	int b = 20;
	int c = a + b;
```


# Byte Order

小端模式，大端模式
    
    cpu大小端模式 - 字节序(Byte Order)
        小端模式: 数值的低字节存储在低地址处，大部分
        大端模式: 数值的低字节存储在高地址处，网络字节序

    变量地址总结
        一个变量的地址值，是它所有字节地址中的最小的那个地址值

```cpp
	__asm {
		mov eax, 12345678H
	}

	/*
		0x0095FCC8  12 00 00 00
		0x0095FCCC  cc cc cc cc
	*/
	int a = 0x12;
	cout << &a << endl;

	/*
		0x0095FCBC  34 12 00 00
		0x0095FCC0  cc cc cc cc
	*/
	int b = 0x1234;
	cout << &b << endl;

	/*
		0x0095FCB0  56 34 12 00
		0x0095FCB4  cc cc cc cc
	*/
	int c = 0x123456;
	cout << &c << endl;

	/*
		0x0095FCA4  78 56 34 12
		0x0095FCA8  cc cc cc cc
	*/
	int d = 0x12345678;
	cout << &d << endl;
```





```cpp
	/*
		mov         dword ptr [ebp-0Ch],0FFh

		ebp: 0x00c4f9c0
		ebp-0Ch: 0x00c4f9b4
		&a: 0x00c4f9b4

		为什么不直接使用 a 的地址
			多次调用函数，函数内的局部变量的地址值是会发生变化的
				ebp的值改变从而引起 a 的地址的改变

		全局变量的地址就是固定的
	*/
	int a = 0xff;
	cout << &a << endl;
```



```cpp
// 全局变量的地址就是固定的
int id = 6;

void demo() {
	static int x = 10;
	cout << &id << endl;
	cout << &x << endl;
}


int main() {
	
	demo();

	return 0;
}
```

# call 函数地址

```cpp
void func00() {
}
void func01() {
}

int main() {
	/*
		call        00AB1375
		call        00AB1370
	*/
	func00();
	func01();

	return 0;
}
```



# lea dst, [地址值]

    lea: Load Effect Address

    首地址 0x1122，4个字节长度，内容为 4

        lea eax, [1122H]
            eax == 1122H

        mov eax, dword ptr [1122H]
            eax == 4

    变量 == 首地址 + 步长


```cpp
int main() {
	/*
		mov         dword ptr [ebp-0Ch],1

		lea         eax,[ebp-0Ch]
		mov         dword ptr [ebp-18h],eax

		mov         dword ptr [ebp-0Ch],2

		mov         eax,dword ptr [ebp-18h]
		mov         dword ptr [eax],3
	*/
	int id = 1;
	int *p = &id;
	id = 2;
	*p = 3;
	return 0;
}
```



# ret
	函数返回

    EAX - Accumulator for operands and reuslts data

```cpp
/*
mov         eax,dword ptr [ebp+8]
add         eax,dword ptr [ebp+0Ch]
mov         dword ptr [ebp-8],eax
mov         eax,dword ptr [ebp-8]
pop         edi
pop         esi
pop         ebx
mov         esp,ebp
pop         ebp
ret
*/
int test(int x, int y) {
	int c = x + y;
	return c;
}

/*
push        2
push        1
call        0011137A
add         esp,8
mov         dword ptr [ebp-8],eax
mov         eax,dword ptr [ebp-8]
add         eax,1
mov         dword ptr [ebp-8],eax
*/
int main() {
	int x = test(1, 2);
	x = x + 1;
	return 0;
}
```



# add | sub | imul

```cpp
/*
mov         dword ptr [ebp-8],1
mov         dword ptr [ebp-14h],2
mov         dword ptr [ebp-20h],3
mov         dword ptr [ebp-2Ch],4

mov         eax,dword ptr [ebp-8]
add         eax,1
mov         dword ptr [ebp-8],eax

mov         eax,dword ptr [ebp-14h]
sub         eax,2
mov         dword ptr [ebp-14h],eax

imul        eax,dword ptr [ebp-20h],3
mov         dword ptr [ebp-20h],eax
mov         eax,dword ptr [ebp-2Ch]

cdq
and         edx,3
add         eax,edx
sar         eax,2
mov         dword ptr [ebp-2Ch],eax
*/
int main() {

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	a += 1;
	b -= 2;
	c *= 3;
	d /= 4;

	return 0;
}
```


# inc | dec

```cpp
/*
mov         dword ptr [ebp-8],1
mov         dword ptr [ebp-14h],2

mov         eax,dword ptr [ebp-8]
add         eax,1
mov         dword ptr [ebp-8],eax

mov         eax,dword ptr [ebp-14h]
sub         eax,1
mov         dword ptr [ebp-14h],eax

mov         eax,dword ptr [ebp-8]
add         eax,1
mov         dword ptr [ebp-8],eax

mov         eax,dword ptr [ebp-14h]
sub         eax,1
mov         dword ptr [ebp-14h],eax
*/
int main() {

	int a = 1;
	int b = 2;
	
	a++;

	b--;

	++a;

	--b;

	return 0;
}
```


# jmp 内存地址
	(无条件)跳转到某个内存地址去执行代码
	j开头的一般都是跳转,大多数是带条件的跳转，一般跟test、 cmp等指令配合使用

```cpp
/*
001118DE  mov         dword ptr [ebp-8],1
001118E5  mov         dword ptr [ebp-14h],2
001118EC  mov         dword ptr [ebp-20h],0

001118F3  mov         eax,dword ptr [ebp-8]
001118F6  cmp         eax,dword ptr [ebp-14h]
001118F9  jne         00111903

001118FB  mov         eax,dword ptr [ebp-8]
001118FE  mov         dword ptr [ebp-20h],eax
00111901  jmp         00111909

00111903  mov         eax,dword ptr [ebp-14h]
00111906  mov         dword ptr [ebp-20h],eax

00111909  xor         eax,eax
0011190B  pop         edi
0011190C  pop         esi
0011190D  pop         ebx
0011190E  mov         esp,ebp
00111910  pop         ebp
00111911  ret
*/
int main() {

	int a = 1;
	int b = 2;
	int c = 0;

	if (a == b) {
		c = a;
	} else {
		c = b;
	}

	return 0;
}
```
