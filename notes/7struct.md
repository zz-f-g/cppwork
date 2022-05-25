# 结构体

---

## 7.1

用户自定义类型

---

派生类型

- 指针
- 数组（类型相同）
- 结构体（可以包含不相同类型的数据）
- 类
- 共用体

---

## 7.2

结构体类型

---

结构体内部成员命名不可与其他成员相同，但是可以与结构体以外的命名相同。

结构体内部的成员类型可以任意。可以是定义好的结构体或指针。（链表）但是定义顺序必须顺序。结构体==不能嵌套==。

定义结构体不为变量分配内存，使用结构体定义变量才分配内存。

---

结构体的字节对齐

```cpp
struct s1{
    int a;
    short b;
    char c;
};
// a: 4, b: 2, c: 1, void: 1
struct s2{
    short c;
    int a;
    short b;
};
// c: 2, void: 2, a: 4, short: 2, void: 2
struct s3{
    int a;
    short c;
    short b;
};
// a: 4, c: 2, b: 2
```

---

字节对齐：对应数据类型的起始地址必须是类型大小的整数倍

- ``int`` 4 的整数倍
- ``short`` 2 的整数倍
- ``double`` 8 的整数倍
- ``pointer`` 4/8 的整数倍

---

根据上一片的规则得到结构体的规则。

- 结构体的起始地址必须是成员中最大的类型的大小的整数倍
- 结构体大小必须是成员中最大的类型的大小的整数倍
- 结构体中默认会有填充字节来保证各个成员的“整数倍”规则

---

```cpp
struct s1{
    char a;
    int b;
    double c;
};
// a:1, void: 3, b: 4, c: 8
struct s2{
    char a;
    double c;
    int b;
};
// a:1, void: 7, c: 8, b: 4, void: 4
```

---

```cpp
struct s1{
    char a[5];
    char c[3];
    int b;
};
// a: 5, c: 3, b: 8
struct s2{
    char a[5];
    int b;
    char c[3];
};
// a:5, void: 3, b: 4, c: 3, void: 1
```

---

结构体变量的定义

1. 先定义类型再定义变量
```cpp
struct STR{
    int a;
    char b;
}; // in head file
struct STR a; // C++ 可以省略 struct
```

2. 定义类型同时定义变量
```cpp
struct STR{
    int a;
    char b;
} s1, s2[10];
struct STR s3;
```

3. 不常用
```cpp
struct {
    int a;
    char b;
} s1, s2[10];
```

---

结构体初始化

1. 各成员对应依次列出大括号
2. 嵌套结构体：大括号中大括号（嵌套初始化）
3. 同类结构体赋值
4. 分别调用成员赋值

---

成员调用

```cpp
struct STR s1;
s1.a;
```

运算优先级次高，仅低于 C++ 中的作用域解析运算符，C 中最高优先级。

结构体不能直接使用标准输入输出进行赋值。

---

结构体变量数组

---

指针指向结构体变量

```cpp
struct student s1;
&s1;
&s1.age;
```

---

间接成员运算符

```cpp
struct student a, *p = a;
p->name;
```

---

- 结构体作为函数参数
- 结构体指针作为函数参数
- 结构体在函数中引用

---

- 结构体声明前，不可以使用结构体。
- 结构体声明后，定义前，可以使用结构体，不可以定义结构体变量，调用成员。
- 结构体定义后，可自由使用。
- 其他源文件中，声明前不可以使用结构体，声明后可以定义指针，但是不能定义结构体变量，访问成员。

如何在没有定义结构体的源文件中自由使用结构体？

只能使用头文件。

---

## 7.3

枚举

---

当一个变量的取值有限，离散而且可列，可以使用枚举类型。

举例：性别、星期、月份、血型

```cpp
enum var { enum1, enum2, <...> };
enum gender {male, female};
enum week {Mon, Tue, Wed, Thu, Fri, Sat, Sum};
```

枚举元素不是字符串，不加双引号，在编译过程中视为整数，默认从 0 开始递增，可以指定。

```cpp
enum week {Sum = 7, Mon = 1, Tue, Wed, Thu, Fri, Sat};
```

---

如果两个枚举元素的整数值相等，不报错，但是比较过程中容易不可读。

定义枚举变量时，``enum`` 可以在 C++ 中省略。

```cpp
enum week w1, w2;
w1 = Mon;
w2 = Fri;
w1 = (week)3;
w1 = week(3);
w1 > w2; // 比较的是整数的值
cout << w1 << endl; // OUTPUT: 3
```

直接输出只能输出整数，可以定义 ``switch case`` 来间接输出。

---

直接输入只能使用 C 方式
```c
scanf("%d", &w1); // 0-6
```

认为保证输入正确。

间接输入：``strcmp()`` 等等

---

## 7.4

typedef 声明类型

---

用新名称来命名已有的数据类型

```cpp
typedef int I4;
typedef struct student STUDENT;
typedef int ARRAY[10];
typedef char * STRING;
ARRAY a, b[5]; // <=> int a[10], b[5][10];
```

可以与原类型混用不需要强制类型转换。

函数重载使用相同的也会报错
```cpp
int fun(int);
I4 fun(I4); // ERROR!!!
```

---

