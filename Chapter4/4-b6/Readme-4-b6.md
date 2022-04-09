# Legendre 多项式

用递归法求解 $n$ 阶 Legendre 多项式的值。
$$
P_{n}(x) = \left\{
\begin{aligned}
    &1 && (n = 0) \\
    &x && (n = 1) \\
    & \frac{1}{n} [(2n - 1) x P_{n-1}(x) - (n-1) P_{n-2}(x)] && (n>1)
\end{aligned}\right.
$$