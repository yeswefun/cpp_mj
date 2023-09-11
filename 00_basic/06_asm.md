

指针的本质

    指针常量
        int * const p = &id;
        注: 指针常量必须初始化

    常量指针
        const int *p = &id;
        int const *p = &id;

    只读指针
        const int * const p = &id;

```cpp
/*
mov         dword ptr [ebp-0Ch],0

lea         eax,[ebp-0Ch]
mov         dword ptr [ebp-18h],eax

mov         eax,dword ptr [ebp-18h]
mov         dword ptr [eax],0Ah
*/
int main() {

	int id = 0;
	int *p = &id;
	*p = 10;

	return 0;
}
```


```cpp
/*
mov         dword ptr [ebp-0Ch],0

lea         eax,[ebp-0Ch]
mov         dword ptr [ebp-18h],eax

mov         eax,dword ptr [ebp-18h]
mov         dword ptr [eax],0Ah
*/
int main() {

	int id = 0;
	int &r = id;
	r = 10;

	return 0;
}
```



