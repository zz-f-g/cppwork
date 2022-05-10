# array

---

## 5.1

基本概念

---

引入：表示相同类型、含义的数据。避免了用多个变量的不统一性。

---

## 5.2

一维数组

---

```cpp
<typename> <array_name>[<positive const int>];
```

```cpp
int k = 10;
int a[k]; // NOT ALLOWED
```

---

数组的大小在声明的时候确定，不能动态定义，在内存中顺序存放，占用连续的空间。

全局数组在不初始化的时候默认每个元素都是 0.

---

数组引用时数组超范围，==不会报错==。

---

数组定义时初始化

```cpp
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // All init
int a[5] = {1, 2, 3, 4, 5, 6}; // ERROR
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// sizeof(a)/sizeof(a[0}) = 10
int a[10] = {5, -2, 7}; // Part init
// a[0] = 5
// a[1] = -2
// a[2] = 7
int a[1000] = {0}; // All init as 0
int a[1000] = {1}; // a[0] = 1, else init as 0
```

---

## 5.3

二维数组

---

```cpp
<typename> arr_name[n_row][n_col];
```

---

在内存中存放时，**先行后列**，连续存放。

在物理存储方式上，二维数组就是一维数组。

---

在逻辑上，二维数组可以看作每个元素是一维数组的一维数组。

```cpp
#include <iostream>
int main()
{
    int a[3][4];
    std::cout << sizeof(a) << std::endl; // 48
    std::cout << sizeof(a[0]) << std::endl; // 16
    std::cout << sizeof(a[0][0]) << std::endl; // 4
    return 0;
}
```

---

初始化

不带内括号按先行后列分配，否则按内括号分配。

```cpp
int a[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
```

不允许缺省列。

```cpp
int a[3][4] = {1, 5, 9};
int a[3][4] = {{1}, {5, 6}};
int a[3][4] = {{1}, {}, {9, 10}};
int a[][4] = {{1}, {5}, {9}};
int a[][4] = {{1}, {}, {9, 10}};
int a[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // still 3 向上取整
```

---

## 5.4

用数组名作为函数实参

---

- 数组元素作为实参
- 一维数组名作为实参 ``<return_type> func_name(<type_name> arr[])``

---

```cpp
void myfunc(int arr[])
{
    cout << sizeof(arr) << endl; // 4
}

int main()
{
    int x[10] = { 1, 2, 3 };
    cout << sizeof(arr) << endl; // 40
    myfunc(x);
    return 0;
}
```

---

多维数组名作为函数实参

```cpp
int max_val(int arr[][N]); // N is necessary!
```

N 必须和实参的列数一致。可以理解为必须给出**一维数组**的数据类型：**大小为多少的数组**。

行随便，可以不写，可以相等，可以不相等（不推荐！），这一点和一维数组作为实参一致。

---

## 5.5

字符数组

---

字符串的尾零 ``\0``。

暂时不考虑字符串中存在 ``\0`` 的情况，可以用一维数组表示字符串。

---

字符数组的初始化

```cpp
char a[5] = { 'c', 'h', 'i', 'n', 'a' };
char a[5] = { 99, 104, 105, 110, 97 };
char a[5] = { '\143', '\150', 105, 110, 97 };
```

可以混合定义

---

尾零在三种情况下输出情况不同

- 新版
- 旧版宋体 28
- 旧版宋体 16

因此不要采用字符形式输出非显示字符。

---

```cpp
sizeof("hello"); // 6
strlen("hello"); // 5
```

字符串长度：``\0`` 前字符的数量，如果没有就不是字符串
字符数组的长度：数组开辟的空间数量

---

用字符串常量初始化字符数组

```cpp
char[6] = {"China"};
char[6] = "China";
char[5] = "China"; // ERROR!!!
```

部分初始化

```cpp
char[10] = "China"; // { ('C', 'h', 'i', 'n', 'a', '\0'), '\0', '\0', '\0'}
```

---

多个字符串初始化二维字符数组

- 字符串的个数不超过行数
- 字符串长度 + 1 不超过列数

字符串或字符数组都不能实现整体赋值，只能单个幅值。

---

当以字符串方式输出尾零时，不会输出。

当以字符方式输出尾零时，**可能**会输出一个字符（==应该避免==）

---

字符数组的输入

C 方式在用 ``scanf("%c, &var")`` 读入字符时，==会将换行作为输入==。注意和 ``cin`` 区分。

C 方式在用 ``scanf("%s, array")`` 读入字符串时，==会将换行和空格作为输入结束的标志，但不会将换行读入==，这一点和 ``cin`` 是相同的。

在不调整高级设置的条件下，``scanf()`` 和 ``cin`` 都是无法为字符串输入空格和换行的。可以实现这个功能的函数有：

- VS2022: ``gets_s``, ``fgets``
- Dev C++: ``gets``, ``fgets``

---

prototype of ``fgets()``

```cpp
fgets(char str[], unsigned int maxsize, stdin);
```

可以读取空格和换行，且多输入不会报错（因为传入了数组长度）。

相比之下，VS2022 ``gets_s()`` & Dev C++ ``gets()`` 只能多读取空格，多输入仍然会报错。

---

| I/O                        | C                        | C++                |
| -------------------------- | ------------------------ | ------------------ |
| input single char          | ``scanf("%c", &var)``    | ``cin >> var``     |
| input string               | ``scanf("%s", arr)``     | ``cin >> arr``     |
| input string from any elem | ``scanf("%s", &arr[n])`` | ``cin >> &arr[n]`` |
| output single char          | ``printf("%c", &var)``    | ``cout << var``     |
| output string               | ``printf("%s", arr)``     | ``cout << arr``     |
| output string from any elem | ``printf("%s", &arr[n])`` | ``cout << &arr[n]`` |

给格式化字符串 ``%s`` 对应的变量是字符指针类型，但是给 ``%c`` 的是字符类型。

---

## 5.6

常用的字符串处理函数

---

操作对象：一维数组表示的字符串

头文件：``string.h`` ``cstring``

VS 编译器认为部分函数（包含了写操作）不安全，要在宏部分做声明。

```cpp
#define _CRT_SECURE_NO_WARNINGS

strlen (const char s[]); // 字符串长度：第一个尾零之前的字符个数
strcat (char dst[], const char src[]);
strncat(char dst[], const char src[], const unsigned int len);
strcpy (char dst[], const char src[]);
strncpy(char dst[], const char src[], const unsigned int len);
strcmp (const char s1[], const char s2[]);
strncmp(const char s1[], const char s2[], const unsigned int len);
```

---

```cpp
strcat(char dst[], const char src[]); // 字符串拼接，将 src[] 接在 dst[] 后面
```

注意 ``dst[]`` 的空间要足够大，大于两个字符串的总长度 + 1。否则==弹窗报错==。

字符串拼接的实现细节：

1. 找到数组 ``dst[]`` 的第一个尾零
2. 从第一个尾零开始覆盖数组 ``src[]`` 的内容
3. 覆盖到 ``src[]`` 出现第一个尾零位置（当然尾零也要复制过去）

---

```cpp
strncat(char dst[], const char src[], const unsigned int n); // 将 src[] 的前 n 个接在 dst[] 后面
```

如果 ``strlen(src) < n``，则全部复制拼接。

``dst[]`` 的空间大于 ``strlen(dst) + n + 1``.

不是 ``strlen(dst) + min(n, strlen(src)) + 1``

---

```cpp
strcpy(char dst[], const char src[]); // 将 src[] 覆盖 dst[]
```

数组 ``dst[]`` 的长度要大于 ``strlen(src) + 1``.

```cpp
char a[] = "123456";
char b[] = "543\0234619267419";
strcpy(a, b);
a // "543\00056\0"
```

---

```cpp
strncpy(char dst[], const char src[], const unsigned int n); // 将 src[] 的前 n 个复制到 dst[]
```

如果 ``strlen(src) < n``，全部复制，复制的长度是 ``strlen(src)``.

如果 ``strlen(src) >= n``，部分复制，只复制前 ``n`` 个字符（不包括尾零）

``dst[]`` 的空间大于 ``min(n, strlen(src) + 1)``.

---

```cpp
int strcmp(const char str1, const char str2);
```

```cpp
char str1[] = "house", str2[] = "horse"; // > 0, 'u' > 'r'
char str3[] = "abcd", str4[] = "abcd"; // 0
char str5[] = "abcd", str6[] = "abc"; // < 0
char str6[] = "abcde", str8[] = "abcd"; // > 0
char str8[] = "abcd", str10[] = "abcd\0horse"; // 0
```

两个字符串取相同位置的字符依次比较，若不等则返回非零，重复到两个字符串都到了尾零则返回 0.

将字符串名字直接比较，比较的是指针的位置，无意义。

---

```cpp
int strncmp(const char s1[], const char s2[], const unsigned int n);
```

比较两个字符串的前 ``n`` 个字符是否一致。

---

## 5.7

string 类

---

C++ 的任意长度字符串方式，不是非原生的类型。

```cpp
#include <string> // not <cstring> or <string.h>

string s = "hello"; // no length limit!
s[2] = 'p'; // heplo
// only cin/cout
string s2 = s; // 不必考虑溢出
s = s + s2; // 不必考虑溢出
s > s2; // 字符串的比较
```

---

## 5.8

补充

---

### cin 成员函数

---

文件结束符：表示文件结束的特殊标记

一般使用 ``CTRL + Z`` 表示键盘输入文件结束符

文件结束标记：判断文件是否结束的特殊标记，用宏定义 ``EOF`` (End of File) 来表示

- 不同的系统 ``EOF`` 的值可能不同。
- 一般只用于字符输入流的判断。

---

简单的 ``cin >> ch`` 只能读取非空白字符，不能读取空格和换行等，但是 ``cin.get()`` 可以

- ``cin.get()`` 从输入流中读取一个字符并返回
- ``cin.get(char ch)`` 从输入流中读取一个字符给 ``ch``，返回**流对象自身** ``cin``（不能和字符类型比较）
- ``cin.get(char str[], unsigned int n, char end)`` 从输入流中读取 ``n - 1`` 个字符到数组中（如果不够会继续等待输入），遇到 ``end`` 提前结束，都返回流对象自身 ``cin``
- ``cin.getline(char str[], unsigned int n, char end)`` 同三个参数的 ``cin.get()``，区别：
    - ``getline``：遇见终止字符，读掉中止字符，不改变缓冲区后续内容
    - ``get``：遇见终止字符，清除缓冲区后续内容

---

``cin.get(ch)`` 只是一个单纯的函数执行, 对 ``ch`` 的值没有影响（传进去的参数是 ``ch`` 的一个复本）

但是 ``ch = cin.get()`` 是一个赋值操作，对 ``ch`` 的值有影响。  

采用 ``cin.get(ch)`` 的时候运行时输入一个 ``^Z`` 程序就结束了。  

而采用 ``cin>>`` 的时候，输入 ``^Z`` 按回车程序并不结束，可以继续输入，除非紧接着又输入了一个 ``^Z``，程序才结束。  

---
  
输入缓冲是行缓冲。当从键盘上输入一串字符并按回车后，这些字符会首先被送到输入缓冲区中存储。

每当按 下回车键后，``cin.get()`` 就会检测输入缓冲区中是否有了可读的数据。``cin.get()`` 还会对键盘上是否有作为流结束标志的 ``Ctrl+Z`` 或者 ``Ctrl+D`` 键按下作出检查，其检查的方式有两种：阻塞式以及非阻塞式。

---

阻塞式检查方式指的是只有在回车键按下之后才对此前是否有 ``Ctrl+Z`` 组合键按下进行检查，非阻塞式样指的是按下 ``Ctrl+D`` 之后立即响应的方式。如果在按 ``Ctrl+D`` 之前已经从键盘输入了字符，则 ``Ctrl+D`` 的作用就相当于回车，即把这些字符送到输入缓冲区供读取使用，此时 ``Ctrl+D`` 不再起流结束符的作用。如果按 ``Ctrl+D`` 之前没有任何键盘输入，则 ``Ctrl+D`` 就是流结束的信号。

---

Windows 系统中一般采用阻塞式检查 ``Ctrl+Z``、Unix/Linux 系统下一般采用非阻塞式的检查 ``Ctrl+D``。

阻塞式方式的特点

- 只有按下回车之后才有可能检测在此之前是否有 ``Ctrl+Z`` 按下
- 如果输入缓冲区中有可读的数据则不会检测 ``Ctrl+Z``（因为有要读的数据，还不能认为到了流的末尾）。
- ``Ctrl+Z`` 产生的不是一个普通的 ASCII 码值，也就是说它产生的不是一个字符，所以不会跟其它从键盘上输入的字符一样能够存放在输入缓冲区。

从键盘上输入 ``abcd^z`` 加回车之后在 Windows 系统上是这样处理的：由于回车的作用，前面的 ``abcd`` 等字符被送到输入缓冲区（注意：上面说过了，``^z`` 不会产生字符，所以更不会存储到输入缓冲区，缓冲区中没有 ``^z`` 的存在）。这时，``cin.get()`` 检测到输入缓冲区中已经有数据存在（因此不再检查是否有 ``^z`` 的输入），于是从缓冲中读取相应的数据。如果都读取完了，则输入缓冲区重新变为 空，``cin.get()`` 等待新的输入。可见，尽管有 ``^z`` 按下，但是由于在此之前还有其它输入字符（abcd），所以流也不会结束。        

因此，输入流结束的条件就是：``^z`` 之前不能有任何字符输入（回车除外），否则 ``^z`` 起不到流结束的作用。

---

### cout 成员函数

---

### C 方式输入输出与字符串

---

``sprintf()`` 将格式化输出的内容放入字符串中。

```c
/*put string printed in str
- input:
    - char str[]: string that to be contained what is printed
    - format_string and output vars
- return value: number of characters printed. [Same as printf()]
- requirement: sizeof(str)/sizeof(str[0]) > return value
*/
#define _CRT_SECURE__NO_WARNINGS
int sprintf(char str[], const char format_str[]<, type var ...>);
```

---

``sscanf()`` 将字符串作为输入从中读取数据

```c
/*use str as input
- input:
    - char str[]: string as input
    - format_string and input vars
- return value: number of vars is input legally. [Same as printf()]
*/
#define _CRT_SECURE__NO_WARNINGS
int sprintf(char str[], const char format_str[]<, type var ...>);
```
