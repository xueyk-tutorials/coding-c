# 指针

C语言中，指针是精髓。指针就是存放内存地址的变量，通过指针操作内存！

- 做不同类型指针转换，可以将变量解析成不同类型数据，特别是配合结构体，最高效和方便的将一段内存解析出想要格式的数据。

- 在嵌入式中，对硬件的控制就是对寄存器的控制，而寄存器是映射到内存地址中，也就是操作内存地址就可以操作寄存器，进而控制硬件！

- 通过传递指针，避免数据传输、参数传递时发生拷贝，提高效率。

## 函数指针
在C语言中，函数名与数组名类似，代表的是一块内存空间，在编译过程有效，运行时被“当作指针“，其本身不是一个变量，故在内存中并不存在一个函数名对应的变量。
函数指针本质就是指针变量，存放了指向函数内存空间的起始地址！

```c
int add(int a, int b)
{
    int c = a+b;
    printf("add: %d+%d=%d\n", a, b, c);
    return c;
}
int main()
{
    typedef int (*calculator)(int,int);
    calculator add1 = add;
    calculator add2 = &add;
    
    add1(1,2);
    (*add1)(1,2);
    add2(1,2);
    (*add2)(1,2);
}
```

指针可以强转，故可以将任意类型指针转成函数指针使用！
```c
int add(int a, int b)
{
    int c = a+b;
    printf("add: %d+%d=%d\n", a, b, c);
    return c;
}

int main()
{
    typedef int (*calculator)(int,int);
    int addr_add = &add;

    ((calculator)addr_add)(2,3);

    return 0;
}
```