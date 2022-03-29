/* 2052110 自动化 郭子瞻 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;
	int lower_limit = 0;
	int upper_limit = 100;

	while (1) {
		printf("请输入x的值[%d-%d] : ", lower_limit, upper_limit);
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		// 这种方法无法检验一种超出 int 范围的错误，比如输入：4294967346(2^32+50)，输出为 50.
		if (ret == 0) {
			scanf("%*[^\n]"); // 采用正则表达式读完换行符之前的内容并舍弃
			scanf("%*c"); // 读取换行符并舍弃
		}
		else if (ret == 1 && (x >= lower_limit && x <= upper_limit))
			break;
	}
	printf("x=%d\n", x);
	return 0;
}
