# DEBUG WITH VISUAL STUDIO 2022

如何使用 Visual Studio 的调试功能？

---

# 部分术语说明

Visual Studio 的调试（debug）菜单如图所示，有以下几个常用的功能：

- 开始调试 F5
- 开始执行（不调试）Ctrl + F5
- 切换端点 F9
- 逐过程 F10
- 逐语句 F11

一般使用两个窗口查看变量的值，以下称为：

- 局部变量窗口
- 监视窗口

---

# 示例程序一：debug1.cpp

```cpp
#include <iostream>
#include <cmath>
using namespace std;

/* calculate x^n
 */
float power(float x, int n)
{
    float res = 1;
    for (int i = 0; i < n; ++i)
        res *= x;
    return res;
}

int main()
{
    int a = 2, *p = &a, &b = a;
    char ch = 'A';
    float f = 1.4f;
    float res;
    cout << ch << endl;
    res = power(f, a);
    cout << sqrt(res) << endl;
    return 0;
}
```

---

# 示例程序二：debug2.cpp

```cpp
#include <iostream>
using namespace std;
#define SIZE 10

void increment()
{
    static int cnt = 0;
    ++cnt;
    cout << "counter: " << cnt << endl;
}

void display(const int * arr, int len)
{
    const int *p = arr;
    while (p < arr + len)
    {
        cout << *p << ' ';
        ++p;
    }
}

int main()
{
    const char *p_ch = "asdf";
    int arr[SIZE] = {0}, *p = arr;
    int matrix[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; ++i)
        matrix[i][i] = 1; // identity matrix
    int len = 5;
    for (int i = 0; i < len; ++i)
    {
        arr[i] = i;
        increment();
    }
    display(arr, len);
    p += (SIZE); // overflow!
    return 0;
}
```

---

# 示例项目三：debug3

```cpp
// debug3-1.cpp
#include <iostream>
using namespace std;

static int static_integer = 314;
extern int external_integer;

int main()
{
    static_integer++;
    external_integer++;
    cout << "static:   " << static_integer << endl;
    cout << "external: " << external_integer << endl;
    return 0;
}
```

```cpp
// debug3-2.cpp
#include <iostream>
using namespace std;

static int static_integer = -1;
int external_integer = 1;
```

---

# Part 1: debug among functions

如何在函数式的程序中使用调试工具进入到需要的语句？

- 1.1 调试的开始和结束
- 1.2 单步执行
- 1.3 执行系统函数但不进入函数体
- 1.4 跳出系统函数的函数体
- 1.5 执行自定义函数但不进入函数体
- 1.6 在自定义函数中单步执行

---

# 1.1 & 1.2 调试的开始和结束、单步执行

开始调试可以直接开始逐过程或逐语句（按 F10/F11）调试，也可以先设置断点（如图）再开始调试（F5），前者只能从 ``main()`` 函数的第一句话开始，后者可以直接跳转到断点所在的位置。

在没有函数的情况下，逐过程和逐语句调试的作用相同：单步调试。

示例程序：debug1.cpp

---

# 1.1 & 1.2 调试的开始和结束、单步执行

结束调试可以逐过程或逐语句执行到 ``main()`` 函数结束，也可以直接结束（Shift + F5）。

示例程序：debug1.cpp

---

# 1.3 & 1.5 执行函数但不进入函数体

使用逐过程调试（F10），可以执行函数但不进入函数体。包括系统函数（如）和自定义函数。如下图所示。

示例程序：debug1.cpp

---

# 1.4 & 1.6 在函数体中使用调试功能

- 可以逐语句调试进入函数体 F11
- 结束在函数体中的调试需要 Shift + F11

示例程序：debug1.cpp

---

# Part 2: debug for variables

如何在调试过程中查看变量的信息？

- 2.1 形参和自动变量的变化
- 2.2 函数体内和体外，静态局部变量的变化
- 2.3 包含多个源程序文件的整个项目中，静态全局变量的变化
- 2.4 包含多个源程序文件的整个项目中，外部全局变量的变化
- 3.1 ``char/int/float``
- 3.2 指向简单变量的指针的地址和指向的值
- 3.3 一维数组
- 3.4 指向一维数组的指针的地址和指向的值
- 3.5 二维数组
- 3.6 在函数中查看传入的一维数组实参的地址和值
- 3.7 指向字符串常量的指针的地址和指向的值
- 3.8 引用
- 3.9 越界的指针

---

# 2.1 & 3.1 & 3.2 & 3.8 简单自动变量

自动变量在赋初值之前是无效值，赋初值以后随着程序的进行而改变，函数结束以后释放。可以在局部变量窗口中查看，也可以在监视窗口中添加要监视的项，输入变量名。

可以在监视窗口中输入 ``*p`` 来查看指针指向的值。

引用类型的值和被引用的变量的值保持一致。

示例程序：debug1.cpp

---

# 2.2 静态局部变量

静态局部变量在改变它的函数体内才会随着程序运行变化，在函数体外即使添加了监视也无法获得静态局部变量的实际值。

示例程序：debug2.cpp

---

# 3.3 & 3.4 & 3.6 一维数组及其指针

在主程序中，可以直接在局部变量窗口中查看数组元素的地址和值，以及其指针的地址和值。

在作为参数被传入的函数中，局部变量窗口中只能看到数组名作为指针的地址和指向的值，不能直接看到所有的元素。需要在监视窗口中输入数组名加中括号加下标的形式来查看特定的元素。

示例程序：debug2.cpp

---

# 3.5 二维数组

二维数组可以看作是一维数组作为元素的一维数组。在局部变量窗口中展现的元素是它的子一维数组。展开它的元素列表，可以看到一维数组中的元素（矩阵中的元素），再展开一维数组的元素列表，就可以直接看到元素了。

---

# 3.7 & 3.9 特殊的指针

- 对于指向常量字符串的指针变量，可以看到无名字符串常量的地址
- 使用指针出现越界访问，可以看到指针的地址和其指向的随机值

示例程序：debug2.cpp

---

# 2.3 & 2.4 多文件项目

对于多文件项目中的静态全局变量和外部全局变量，其逻辑和正常的程序逻辑是一致的，可以在变量的整个作用域中查看其值。

但是有两点需要注意：

1. 调试是从 ``main()`` 函数的第一行开始，无法将断点设置在程序中函数的外部，所有的全局变量在 ``main()`` 函数执行之前就已经声明并赋初值了。
2. VS 的局部变量窗口只能查看在当前函数中作为左值的变量或形参，如果删掉示例程序中 ``main()`` 函数中的前两行，将无法在局部变量窗口中查看两个全局变量的值，需要在监视窗口中添加监视项。
