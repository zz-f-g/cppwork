# 基本递归法求 Fibonacci 数列

$$
\begin{align*}
    F(n) = \left\{ \begin{aligned}
        &1 && (n = 1) \\
        &1 && (n = 2) \\
        &F(n-1) + F(n-2) && (n \geq 3)
    \end{aligned} \right.
\end{align*}
$$

- 不考虑 integer overflow
- 给出递归函数的执行次数和项数的关系的递推公式
