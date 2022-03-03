# 基础知识

---

## 2.1

如何组装计算机？

- CPU
- 主板
- 内存（读写在 ns 数量级）
- 硬盘（读写在 ms 数量级）
- 显卡+显示器
- 键盘鼠标
- 机箱电源
- 打印机等外接设备

---

冯诺依曼架构

```mermaid
flowchart LR
    subgraph CPU
        calculator --> controller
        controller --> calculator
    end
    Input --> CPU --> Output
    Store --> CPU --> Store
```

程序：使 CPU(运算器和控制器) 工作的一串指令。

- Advanced Language
- Machine Language
- Assembly Language

---

Data Structure：编写程序时数据的组织方法。

Linear List vs. Linked LIst

Algorithm: how to make program run effectively.

To calculate $\pi$:

- Iteration
- Monte Carlo

Auto-driving:

- condition recognition
- learn from the old driver

---

Principle of Compile: how to convert advance lang to machine lang.

OS: manage and arange computer resources.

Computer Organization

Network: change data

Sercurity: protect data

Mode Recognition & AI: service

---

Dataset System: combine quantity of data of different types.

Big Data Tech: attain useful information from huge data.

数据库（事务性） vs 数据仓库（分析历史）

数据仓库不要求数据历史长，但要求**大致的准确性**。

---

## 2.2

---

Binary System

bit(b) & byte(B): 1 byte = 8 bit

| KB | MB | GB | TB |
| -- | -- | -- | -- |
| $2^{10}$ | $2^{20}$ | $2^{30}$ | $2^{40}$ |

除了硬盘，U 盘，其他的计算机系统：$1K = 2^{10}$

---

Data Presentation: Binary

- numerals(tel, ...)
- value
- text(encoding system)
- Picture(RGB)
- Video(fps)
- Voice(sample, $\Delta t \rightarrow 0$)
    - audio: 8kHz
    - music: 40kHz

---

## 2.3

---

Introduction to CPP

```c++
#include <iostream> // input-output stream
using namespace std; // standard
int main() // function
{
    int a, b, sum;
    cin >> a >> b; // input
    sum = a + b;
    cout << "a+b=" << sum << endl; // output
    return 0;
}
```

---

basic form:

- head file
- namespace
- constant def
- func def
- global var def
- func 1
- ...
- func n

---

Function is unit of a cpp program.

```mermaid
graph LR
P[A Program] --contains--> F[Many Cpp Files] --contains--> f[Functions]
```

---

```mermaid
graph TD
a.cpp --compile--> a.obj --link--> test.exe
b.cpp --compile--> b.obj --link--> test.exe
c.cpp --compile--> c.obj --link--> test.exe
```

---

- Only one ``main()`` (where the program launches from)
- Funcs from Packages.

---

Component of func:

- return type
- name of func
- formal parameter list
- body of func

- Paralleled definition
- Nested calling

---

Statement is the unit of funcs.

- **End with ;**
- Continue with \ (or default)

- define statement
- execute statement

***Suggestion: One Row One Statement***

Annotation: ``/* */`` ``//``

---

## 2.4

Types

---

Data Types

- Basic Types
    - int (signed and unsigned)
        - short int
        - int
        - long int
        - long long int
    - char (signed and unsigned)
    - float
        - float
        - double
        - long double
    - bool
- Derivate Types
    - pointer
    - enum
    - array
    - struct
    - union
    - class
- Void

---

Based on VS2022 x86

| Types        | bytes |
| ------------ | ----- |
| [signed] int | 4     |
| unsigned int | 4     |

``sizeof(int)``

Different Compiler, Different OS, some differences in bytes of types.

---

Attain min and max values for head file climits.

```c++
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    cout << INT_MIN << endl;
    cout << UINT_MIN << endl;
    cout << LLONG_MAX << endl;
    return 0;
}
```

---

The computer can not use binary system to denote infinity. But infinity can be defined especially.

---

How to denote positive/negative integer in binary system?

Based on short type:

``unsigned short``: 0000 0000 0000 0001 (+1)

``signed short``: 0111 1111 1111 1111 (32767)

bit of sign on the left

- true form (0000 0000 0000 0000 = 1000 0000 0000 0000) **two different codes of 0**
- complement (-x: (not x) + 1)

---

## 2.5

Constant

---

- 字面常量
- 符号常量

---

Constant Value

- Bin: 0b[0-1]
- Dec: [0-9]
- Oct: 0[0-9] (***0123***)
- Hex: 0x[0-9a-f]

---

Decimal is outputed by ``cout`` by default.

``cout << "0x" << hex << 119 << endl;`` --->  ``0x77``

注意区分：

- 内部表示
- 输出显示
- 额外修饰

---

- signed int: 123
- signed long: 123L
- unsigned int: 123U
- unsigned long: 123UL, 123LU

``cout << typeid(123U).name() << endl;`` --->  ``unsigned int``

---

float

- 小数形式
- 指数形式 (float + [e,E] + int)

机内存储：小数点之前为 0，小数点之后第一位不为 0 的指数形式。($0.23 \times 10^{7}$)

这样可以把浮点数存储为两个正数（小数点之后的部分和指数）

---

Physic Storage of Float

31: sign bit
30~23: exponent
22~0: 尾数

![psf](https://pic2.zhimg.com/80/v2-742185fea1b30d11b93df54a91668839_1440w.jpg)

---

- double: 1.23
- float: 1.23F

``sizeof()`` ``typeid().name``

---

ASCII

- 0-32,127: 控制字符
- 33-126: 显示字符

| 0       | space   | A       | a       |
| ------- | ------- | ------- | ------- |
| 48/0x30 | 32/0x20 | 65/0x41 | 97/0x61 |

---

- 普通字符常量 ``'A',' '``
- 转义字符常量 ``'\n','\t','\v','\b','\r','\a','\\','\?','\'','\"'``
    - ``\ddd``：000-377 8 进制对应的 ASCII
    - ``\xhh``：00-ff 8 进制对应的 ASCII，**x 必须小写（和常量的表示不同）**

```
'\101' == 'A' == '\0x41'
'\12' == '\012' = '\n'
```

---

一个字符常量可以有多种表示形式

```
'\n' == '\12' == '\012' == '\xA' == '\x0A' == '\xa' == '\x0a'
'\"' == '\42' == '\042' == '\x22'
```

---

字符在内存中的存储

- 一个字符常量只能表示字符
- 一个字符在内存中占用一个字节（Byte）
- 字节的值为该字符的 ASCII 码

字符常量不能表示汉字。

---

字符串常量

``"string"``

***Difference*** of ' and " in C/CPP.

字符串的长度：字符序列中字符的长度。

``"\r \n \t \\ A \\ t \x1b \" \123 4 \xf t \x2f \33"``: 15

**最长原则**

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << strlen("string") << endl;
    return 0;
}
```

---

字符串在内存中的存放

ASCIIs + ``"\0"``（尾 0）

``""`` & ``" "``

- ``""``: ``'\0'``
- ``" "``: ``'\x20','\0'``

可以用字符串常量表示汉字。

---

符号常量

```cpp
#define pi 3.14159
```

---

## 2.6

Variable

---

标识符

``[A-Za-z_][0-9A-Za-z_]+``

长度小于等于 32.

标识符不能和关键字同名。

---

Define a Variable

```cpp
int c,b,a=b=c=1; // IT IS VALID!!
```

---

Data **overflow** ***isn't*** recognized as error in CPP!

```cpp
short a = -10;
unsigned short b = a; // warning
cout << b << endl; // b = 65526 = 2^{16} - 10
```

---

```cpp
#include <iostream>
using namespace std;

int main()
{
    unsigned long long x = -1LL;
    cout << x/2 << endl;
    return 0;
}
```

---

不同的数据类型相互转换

- 短到长
    - ``signed`` 低位赋值，符号位（**如果有**）填充到所有高位；
    - ``unsigned`` 高位填充 0.
- 长到短
    - 舍弃高位

---

Float

```mermaid
flowchart LR
    float --correct--> double
    double --unknown--> float
```

---

Character

可以作为 1 Byte 的正数参与运算

``char, unsigned char``

---

Constant Variable

常变量必须在定义的时候赋初值，之后不能改变。

---

符号常量和常变量

- 符号常量相当于在程序中把对应的文本替换；
- 而常变量和其他变量一致，都是具有类型的。

```cpp
#include <iostream>
#define pi 3.14;

int main()
{
    double r = 1.0;
    double s = r*r*pi // ;!!!
    std::cout << s << std::endl;
}
```
