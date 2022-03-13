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

机内存储：小数点之前为 1，小数点之后第一位不为 0 的指数形式。($0.23 \times 10^{7}$)

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
    - ``\xhh``：00-ff 16 进制对应的 ASCII，**x 必须小写（和常量的表示不同）**

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

---

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

---

##  2.7

C++ Operator

---

运算符

- 单目
- 双目
- 三目 ``? :``

- 优先性
- 结合性：同级运算符进行混合运算时，按结合性方向依次进行处理。比如加号为从左至右，左结合。

***熟记下发附录 D（运算符的优先级）***

---

基本运算符：``+ - * / %``

- 第五级：``* / %``
- 第六级：``+ -``

都是左结合。

字符型可以参与运算，作为一字节的整数。

```cpp
10 % -3 == 1
-10 % 3 == -1
```

---

```cpp
#include <iostream>
using namespace std;
int main()
{
    const double pi = 3.14;
    double v1, v2;
    int r = 1;
    int h = 2;
    v1 = 1/3*pi*r*r*h; // 0
    v1 = 4/3*pi*r*r*r; // !!!
    return 0;
}
```

---

用栈理解表达式求值过程

- Number Stack
- Operator Stack

如果欲进栈的运算符级别高于或等于（右结合）栈顶运算符，则进栈；

如果欲进栈的运算符级别低于或等于（左结合）栈顶运算符，则先将栈顶运算符的运算执行，再进行相似的判断。

不考虑有括号、单目、三目运算符的真实情况。

---

如果某个运算符涉及的两个数据不是同一类型，则需要先转成同一类型在进行运算。

转换的规则：（从高到低）

- long double
- double
- float
- unsigned long long
- long long
- unsigned long
- long
- unsigned [int]
- int <- char, u_char, short, u_short (*necessary conversion*: **The Integer Promotion**)

---

```cpp
#include <iostream>
using namespace std;

int main()
{
    short a = 1;
    short b = 32767;

    cout << a + b << endl; // 32768 (?-32768)
    cout << 1 + b << endl; // -32768
    cout << sizeof(a + 'A') << endl;
    cout << typeid(a+b).name() << endl;
    return 0;
}
```

**这个问题的核心是之前的整形转换。**

``b+1`` 还是``short``，而 ``a+b`` 是 ``int``。

---

同级 ``signed`` 和 ``unsigned`` 结合时，以 ``unsigned`` 为准。

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 12;
    cout << x-13 << endl; // -1
    unsigned int y = 12;
    cout << x-13 << endl; // lkfhaoehf
    return 0;
}
```

---

类型转换由系统隐式进行。

进行不是一次完成的，而是按照计算的顺序（参见之前的栈规则），一次一次地转化。

---

自增自减运算符

- 前缀：优先级 3 级
- 后缀：优先级 2 级

```cpp
#include <iostream>
using namespace std;
int main()
{
    int i = 3;
    int j = ++i; // 4
    int k = i++; // 3
    return 0;
}
```

---

```cpp
    int i = 3;
    i = i++;
    int j = 3;
    j = j++; // differ in gcc and VC++
```

---

递增运算不影响变量本身，影响表达式。

严格地说前缀效率更高，因为后缀需要临时变量。

递增运算只能对变量进行运算，不能对常量和表达式进行运算。

---

强制类型转换：必须再程序中显式使用。

```c
(int)(a+b);
```

```cpp
int(a+b);
int(a);
static_cast<int>(a+b);
static_cast<int>(a);
```

---

赋值运算和赋值表达式

Left Value Must Be A Variable.

***Warning*** **如果不改直接再次运行，将不会再出现**。

---

- ``float, double`` --->  ``char, short, int, long, long long`` 取整（可能溢出）
- ``char, short, int, long, long long`` --->  ``float, double`` 不变（但是精度可能受影响，小数部分截断）
- ``char, short, int, long, long long`` 按照低位补位，高位截断规则
- ``unsigned`` --->  ``signed`` 二进制码不变

---

复合赋值运算符

``+=, -=, *=, /=, %=`` 这些优先级都**相同**。

---

赋值表达式的值和变量的值相同。

任何表达式都是有值的。

``a = b = c = 5`` => ``a = (b = (c = 5))``

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = b = c = 5; // "b", "c" is not declared in this scope!
    int x;
    long b;
    float c;
    x = b = c = 5.0; // 3 times type conversion
    return 0;
}
```

---


```cpp
#include <iostream>
using namespace std;
int main()
{
    int a;
    (a=3*5)=4*3; // a = 12
    a = 3*5 = 4*3; // Left value!!: 15 = 12
    return 0;
}
```

在执行第二个等号时，等号的左值已经变成了变量 ``a``.

---

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 12;
    a += a -= a * a;
    return 0;
}
```

- 12 * 12; a = 12
- a -= 144; a = 12
- a += -132; a = -132

---

Comma

级别最低的运算符

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = (a=3*5, a*4) // b = 60
    return 0;
}
```

---

表达式均有值，表达式的类型由最后一步的计算决定。

- 算术表达式：只有算术表达式才有隐式类型转换。
- （复合）赋值表达式
- 逗号表达式
