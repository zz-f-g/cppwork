# KFC system

总体要求：

1. 使用结构体
2. 含有不少于 20 种菜品，能够表达单品、组合优惠

细节要求：

1. 显示简单的菜单，每一个餐品对应一个字母
2. 一次输入若干菜品，按回车结束，直接输入 ``0`` 表示退出程序
3. 单品品种不少于 26 种，大小写不敏感，餐品组合字母间无顺序限制
4. 点餐结束以后，根据内容计算价格，组合优惠要考虑
5. 假设优惠组合不会同时出现在点餐结果中
6. 输出结果中相同的餐品要合并，后面加 ``*n``
7. 不用考虑时间限制（比如工作日午餐，周一到五 10:00~14:00）
8. 要求餐品的种类、单价、优惠项目等信息修改以后，程序能够自动适应并打印新信息
9. 