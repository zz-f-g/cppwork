# Function

---

## 4.1

introduction

---

## 4.2

definition

---

无参函数

```
type func_name([void])
{
    ...;
    return ...;
}
```

缺省返回类型

- C: ``int`` by default
- CPP: error

---

有参函数

```
type func_name(type var1[, type var2...])
{
    ...;
    return ...;
}
```

---

## 4.3

parameters and value

---

Parameters

- formal parameter
- actual parameter

---

函数在执行时临时分配空间，在执行结束以后空间释放。

如果之后的函数执行，可能会占用之前的函数的空间。

---

如果返回类型和 ``return`` 的类型不一致，以返回类型为准。

---

如果 ``return`` 语句没有覆盖所有分支，Visual C++ 编译器会警告。

```cpp
int fun(int x)
{
    if (x>1)
        return 1;
    else if (x<=1)
        return 0;
}
```

虽然在事实上覆盖了所有分支，但是在形式上没有。因此也会产生警告。

---

```cpp
int fun()
{
    int i = 0;
    for (i=0; i<=100; i++)
    {
        if (i>=10)
            return 0;
    }
}
```

同理也会报错。

---

```cpp
int fun()
{
    int i = 0;
    for (i=0; ; i++)
    {
        if (i>=10)
            return 0;
    }
}
```

这样不会报错。因为此时程序只有唯一出口。

---

## 4.4

Calling of Function

---

对于多个形参的函数，不要传入同一实参，不同编译器的处理不同。

---

调用库函数

```c
#include <stdio.h>
#include <math.h>
#include <string.h>
```

```cpp
#include <cstdio>
#include <cmath>
#include <cstring>
```

---

函数声明

```
type func_name(type [var1, type var2, ...]);
```

---

## 4.5

函数的嵌套调用

---

C++ 程序的执行过程

1. 从 ``main`` 函数的第一个语句开始一次执行
2. 执行到函数调用语句，则保存调用函数当前的系统信息
3. 转到被调用函数的第一个执行语句开始执行
4. 被调用函数执行完成后，返回被调用函数的调用处，恢复调用前保存的系统信息
5. 如果被调用函数中仍有调用其他函数的语句，按照栈的规则嵌套执行上述步骤 2-4.
6. 所有被调用函数执行完成以后，回到 ``main`` 函数顺序执行。

---

## 4.6

递归

---

- 直接递归
- 间接递归

必然有条件判断是否进入下一次递归。

---

递归的求解过程

1. 回推：找到结果
2. 递推：从结果推回需要的

---

```cpp
void num_sys_convert(int n, int base)
{
    if (n >= base)
        num_sys_convert(n / base, base);
    cout << n % base;
    cout << endl;
}
```

---

## 4.7

内联函数

---

```cpp
inline int max(int x, int y)
{
    return (x >= y) ? x : y;
}
```

直接将函数中的语句插入调用函数的位置，在执行过程中**不存在调用栈的过程**。

因此使用 ``inline`` 可以用空间换取时间，避免了“保存和恢复现场”所花费的时间。

内联函数的写法是否编译成是真实的内联函数，这是由编译器决定的。

在内联函数中不能有复杂的分支、循环语句。

---

```cpp
#include <iostream>
using namespace std;
inline swap(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    int x, y;
    x = 1;
    y = 0;
    cout << "x=" << x << ", y=" << y << endl; // x=1, y=0
    swap(x, y);
    cout << "x=" << x << ", y=" << y << endl; // x=1, y=0
    return 0;
}
```

---

不同的编译器对 ``inline`` 到底写在原型还是构造的位置的规定不同。

``inline`` 函数和调用函数必须写在同一个源程序文件中。普通函数可以不这样。

---

## 4.8

重载

---

定义：同一作用域内中的多个函数使用相同的函数名。

引入的原因：

1. 对不同类型的参数实现相同的功能，希望使用相同的函数名字
2. 对不同数量的参数实现相同的功能，希望使用相同的函数名字

上面两种情况，C++ 都允许，C 都不允许。

---

重载函数调用的匹配查找顺序