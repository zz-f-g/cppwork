# 使用函数模板实现累加

注意：不能使用求和公式

```cpp
template <typename T>
T add(T n)
{
    return n * (n + 1) / 2 // 可能出现越界
}
```
