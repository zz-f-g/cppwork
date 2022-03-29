/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int x;
	int lower_limit = 0;
	int upper_limit = 100;

	while (1) {
		cout << "请输入x的值[" << lower_limit << "-" << upper_limit << "] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (x >= lower_limit && x <= upper_limit)
			break;

/*
资料来源：
https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
*/
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}

