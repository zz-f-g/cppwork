# 和为 1953

- 输出：用 1 - 9 组成三个三位数，和为 1953，输出并统计个数个时间
- 排序规则：
    - 组合内部，三个数升序排列（相同组合算一种）
    - 不同组合之间，第一个数升序排列
    - 第二个三位数在第一个三位数相同的情况下升序排列
 - 序号输出格式：``No.`` + 三位序号（右对齐）

事实上不必使用三重循环，使用两重循环得到第一个和第二个数，通过减法得到第三个数再判断是否存在数字为零或重复的情况。

相对来说，九重循环比三重循环能排除掉数字为零的情况，比三重循环天生更优。

数学角度分析
$$
\begin{align*}
    & 1+2+\cdots+9 = 45 \\
    & b1 + b2 + b3 = 17, 18, 19 \\
    & g1 + g2 + g3 = 3, 13, 23 \\
    & g1 + g2 + g3 \neq 3\\
    & 17 + 23 = 40 \Rightarrow g1 + g2 + g3 \neq 23 \\
    & g1 + g2 + g3 = 13
\end{align*}
$$

在算法比较优，时间复杂度较低的情况下，输出所占的时间占比越来越高。

一般来说，``printf()`` 比 ``cout`` 语句输出更快，但是相对不安全。
