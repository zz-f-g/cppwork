# 递归法求 Fibonacci 数列中的递归次数分析

相关的函数如下：
```cpp
int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
```
设输入为 $n$ 时，函数调用了 $a_{n}$ 次。有初始条件：
$$
\begin{align*}
    & a_{1} = 1 \\
    & a_{2} = 1
\end{align*}
$$
对于 $n$ 较大的情况，首先调用一次，接着再依次调用 $n-1$ 和 $n-2$. 得到递推公式：
$$
a_{n} = a_{n-1} + a_{n-2} + 1
$$
可以构造程序计算不同输入对应的递归次数
```cpp
#include <iostream>
using namespace std;
long long recursion_times(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return recursion_times(n - 1) + recursion_times(n - 2) + 1
}
int main()
{
    int n = 1;
    for (; n <= 46; ++n)
    {
        cout << "a(" << n << ")=" << recursion_times(n) << endl;
    }
    return 0;
}
```
输出结果如下

![[Chapter4/4-b8/images/Pasted image 20220409140530.png]]

计算一个 Fibonacci 数列中的数所需要进行的递归次数比这个数本身还要大。
