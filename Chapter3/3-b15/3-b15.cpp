/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;

int main()
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << j << "x" << i << "=" << i * j;
			if (i * j < 10)
				cout << "   ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

