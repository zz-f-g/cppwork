# 人民币阿拉伯数字转大写

承接：[[Readme-3-b12]]

- 输入：【0 ~ 100 亿）的浮点数，最多输入到小数点后两位
- 输出：大写表示
- 大写标准汉字：
  - 零壹贰叁肆伍陆柒捌玖
  - 亿万仟佰拾
  - 圆角分整
- 含零输出规则：中文每 4 位一组，如果存在不相邻的非零高位和低位，则中间仅输出一个“零”，例如：
  - 2040
  - 2003
  - \*0306
  - \*0346
  - \*0046
- “整”的输出：若角、分为 0，“圆整”；若分为 0，“角整”。
- 必须使用不得修改的 ``daxie()`` 函数输出
