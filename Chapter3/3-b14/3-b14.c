/* 2052110 自动化 郭子瞻 */

#include <stdio.h>

int main()
{
	int num;
	int factor;
	int sum = 0;
	for (num = 2; num <= 1000; ++num)
	{
		for (factor = 1; factor <= num / 2; ++factor)
		{
			if (num % factor == 0)
				sum += factor;
		}
		if (sum == num)
		{
			printf("%d,its factors are 1", num);
			for (factor = 2; factor <= num / 2; ++factor)
			{
				if (num % factor == 0)
					printf(",%d", factor);
			}
			printf("\n");
		}
		sum = 0;
	}

	return 0;
}
