/* 2052110 ����հ �Զ��� */

#include <iostream>
#include <cmath>
using namespace std;

/* ----����Ҫ��----
   1����������������ͷ�ļ�
   2������������ȫ�ֱ�������̬�ֲ�����
   3��������������������
   4�������������������κ���ʽ��ѭ��
   --------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�legendre
  ��    �ܣ�����n��legendre����ʽ��ֵ
  ���������double x: ����ʽ���Ա���; int n: ����ʽ�Ľ���.
  �� �� ֵ������ʽ��ֵ
  ˵    �������������βΡ��������;���׼��
***************************************************************************/
double legendre(double x, int n)
{
	if (n == 0)
		return 1.0;
	else if (n == 1)
		return x;
	else
		return ((2 * n - 1) * x * legendre(x, n - 1) -  legendre(x, n - 2) * (n - 1)) / n;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����������롢���õݹ麯�������
***************************************************************************/
int main()
{
	double x;
	int n;
	cout << "����legendre��������x��n��ֵ" << endl;
	cin >> x >> n;
	cout << "legendre[" << n << "](" << x << ")=" << legendre(x, n) << endl;
	return 0;
}
