# 密码生成

使用基本 ASCII 字符构建满足指定长度条件和各类字符数量条件的密码。

输入：

1. 密码总长度（12 ~ 16）
2. 大写字母最少个数（$\geq 2$）
3. 小写字母最少个数（$\geq 2$）
4. 数字最少个数（$\geq 2$）
5. 其他符号最少个数（$\geq 2$）

其他符号从下面的数组中选取

```cpp
static const char other[] = "!@#$%^&*-_=+,.?";
```

输入的值要做判断，如果错误给出错误信息

1. 非法输入字符
2. 超出给定范围
3. 密码总长度小于各类字符最少个数之和

要保证密码的==随机性==。

每次输出 10 个密码，以便观察。
