/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;

/***************************************************************************
  �������ƣ�daxie()
  ��    �ܣ������д��0~9
  ������������֣�����
  �� �� ֵ����
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/***************************************************************************
  �������ƣ�main()
  ��    �ܣ������ת��д
  �����������
  �� �� ֵ�����ͣ������˳����� 0
  ˵    ����������
***************************************************************************/
int main()
{
	int zero_flag = 0;
	int higher_flag = 0;

	cout << "������[0-100��)֮�������:\n";
	double n;
	cin >> n;

	if (n >= 1e10 || n < 0)
		return 0;

	int d0, d1, d2, d3;
	int d4, d5, d6, d7;
	int d8, d9;
	int d_1, d_2;

	d9 = (int)(n / 1e9);
	n -= d9 * 1e9;
	d8 = (int)(n / 1e8);
	n -= d8 * 1e8;

	d7 = (int)(n / 1e7);
	n -= d7 * 1e7;
	d6 = (int)(n / 1e6);
	n -= d6 * 1e6;
	d5 = (int)(n / 1e5);
	n -= d5 * 1e5;
	d4 = (int)(n / 1e4);
	n -= d4 * 1e4;

	d3 = (int)(n / 1e3);
	n -= d3 * 1e3;
	d2 = (int)(n / 100);
	n -= d2 * 100;
	d1 = (int)(n / 10);
	n -= d1 * 10;
	d0 = (int)n;
	n -= d0;

	d_1 = (int)((n + 0.001) / 0.1);
	n -= 0.1 * d_1;
	d_2 = (int)((n + 0.001) / 0.01);

	cout << "��д�����:\n";

	if (d_2 == 0 && d_1 == 0
		&& d0 == 0 && d1 == 0 && d2 == 0 && d3 == 0
		&& d4 == 0 && d5 == 0 && d6 == 0 && d7 == 0
		&& d8 == 0 && d9 == 0)
	{
		cout << "��Բ��\n";
		return 0;
	}

	//ʮ��
	daxie(d9, zero_flag);
	if (d9)
		cout << "ʰ";

	//��
	daxie(d8, zero_flag);
	if (d8 + d9 > 0)
	{
		cout << "��";
		higher_flag = 1;
	}

	//ǧ��
	zero_flag = (higher_flag && (d6 || d5 || d4)) ? 1 : 0;
	daxie(d7, zero_flag);
	if (d7)
		cout << "Ǫ";

	//����
	zero_flag = (higher_flag && d7 && (d5 || d4)) ? 1 : 0;
	daxie(d6, zero_flag);
	if (d6)
		cout << "��";

	//ʮ��
	zero_flag = (higher_flag && (d7 || d6) && d4) ? 1 : 0;
	daxie(d5, zero_flag);
	if (d5)
		cout << "ʰ";

	//��
	zero_flag = 0;
	daxie(d4, zero_flag);
	if (d7 || d6 || d5 || d4)
		cout << "��";

	higher_flag = higher_flag || (d7 != 0) || (d6 != 0) || (d5 != 0) || (d4 != 0);

	//ǧ
	zero_flag = (higher_flag && (d2 || d1 || d0)) ? 1 : 0;
	daxie(d3, zero_flag);
	if (d3)
		cout << "Ǫ";

	//��
	zero_flag = (higher_flag && d3 && (d1 || d0)) ? 1 : 0;
	daxie(d2, zero_flag);
	if (d2)
		cout << "��";

	//ʮ
	zero_flag = (higher_flag && (d3 || d2) && d0) ? 1 : 0;
	daxie(d1, zero_flag);
	if (d1)
		cout << "ʰ";

	//��
	zero_flag = 0;
	daxie(d0, zero_flag);

	higher_flag = higher_flag || (d3 != 0) || (d2 != 0) || (d1 != 0) || (d0 != 0);

	if (higher_flag)
		cout << "Բ";
	else
		cout << "��Բ";

	if (d_1 == 0 && d_2 == 0)
		cout << "��";
	else
	{
		//��
		daxie(d_1, d_2);
		cout << "��";

		//��
		if (d_2)
		{
			daxie(d_2, 0);
			cout << "��";
		}
		else
			cout << "��";
	}
	cout << endl;

	return 0;
}