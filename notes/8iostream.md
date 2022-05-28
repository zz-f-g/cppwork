# 输入输出流

---

## 8.1

C++ input & output

---

流：字符流，由一系列字节构成，传给对应设备。

---

字符输入判断换行

- ``getchar()`` ``\n``
- ``_getch()`` ``\r``

---

输入输出的种类：

1. 系统设备：键盘、显示器、鼠标、打印机、扫描仪等
2. 外存文件：从文件中得到输入、输出到文件中
3. 内存空间：输入、输出到一段内存中，如数组、``string`` 类

``<cstring>/<string.h>`` 和 ``<string>`` 头文件的区别

操作系统将所有的系统设备统一当作文件处理。

> 一切皆文件。

---

C++ 的输入输出兼容 C 的 ``scanf(), printf()`` 但是是==类型安全的==。

```c
short k;
scanf("%d", &k);
```

程序编译完成生成警告，运行过程中（输入结束后）崩溃。

本质上和数组越界是一样的。

---

## 8.2

标准输出流

---

- ``cout``
- ``cerr`` 标准输出输出设备，不等待回车直接输出
- ``clog`` 标准错误输出设备，等待回车

---

```cpp
cout.put(72).put(102).put(45);
```

``cout.put()`` 可以连续使用，就像流插入一样。

---

## 8.3

标准输入流

---

文件结束符

CTRL+Z

文件结束标记

```cpp
#define EOF -1 // 绝大部分系统
```

---

- ``cin.get()``
- ``cin.get(char)``
- ``cin.get(char *, int n, char)``
- ``cin.getline(char *, int n, char)``
- ``cin.eof()``
- ``cin.peek()``
- ``cin.putback()``
- ``cin.ignore()``

---

## 8.4

文件

---

文件：存储在外存储器上的数据的结合

文件名：操作系统用于访问文件的依据

---

C++ 对文件的访问

- 低级访问：纯字节的、无格式的
- 高级访问：有格式的，转化为特定数据的

---

文件流类和文件流对象

- ifstream: input
- ofstream: output
- fstream: both input and output

将类名写在对象名之前可以定义流对象。

---

```cpp
#include <fstream>
```

多种打开方式，可以使用位运算或 ``|`` 来同时使用多种打开方式。

文件名可以带路径：绝对、相对

不带路径默认在程序相同的路径。

什么是当前路径？

对于 cmd 窗口中运行的二进制可执行文件，当前路径是 ``*.exe`` 的路径。

对于 VS 集成环境中，当前路径是 ``*.cpp`` 的路径。

---

```cpp
ofstream out("path", ios::out);
ofstream out;
out.open("path", ios::out);
```

---

文件指针

打开文件以后存在文件指针，根据打开方式的不同初始指向文件的开始或者末尾。

---

执行 ``open()`` 要判断是否成功打开

```cpp
if (!out)
if (out.is_open() == 0)
if (!out.is_open())
```

``out`` 是流对象，不是指针。

---

文件的关闭

```cpp
out.close();
```

---

对文本文件的操作

基本方法：将文件流对象名当作 ``cin/cout`` 对象直接读入读出

```cpp
out << a << endl;
```

---

```cpp
while (in.get(ch))
{
    out.put(ch);
}
while (!in.eof())
{
    out.put(ch);
}
```

有什么不同？猜想：文件结束符。

---

二进制文件的特殊读写方法

```cpp
int main()
{
    ofstream out("out.txt", ios::out);
    int i = 1234567;
    float f = 123.456f;
    double d = 123.456;
    out.write((char *)&i, sizeof(int));
    out.write((char *)&f, sizeof(float));
    out.write((char *)&d, sizeof(double));
    out.close;
    return 0;
}
```

在文件中写入二进制数据。

---

