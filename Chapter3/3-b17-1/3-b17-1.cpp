/* 2052110 �Զ��� ����հ */

#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int x;
	int lower_limit = 0;
	int upper_limit = 100;

	while (1) {
		cout << "������x��ֵ[" << lower_limit << "-" << upper_limit << "] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (x >= lower_limit && x <= upper_limit)
			break;

/*
������Դ��
https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
*/
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1

	return 0;
}

