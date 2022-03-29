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

