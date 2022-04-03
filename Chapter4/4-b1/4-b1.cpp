/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：daxie()
  功    能：输出大写的0~9
  输入参数：数字，零标记
  返 回 值：无
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/***************************************************************************
  函数名称：main()
  功    能：人民币转大写
  输入参数：无
  返 回 值：整型，正常退出返回 0
  说    明：主函数
***************************************************************************/
int main()
{
	int zero_flag = 0;
	int higher_flag = 0;

	cout << "请输入[0-100亿)之间的数字:\n";
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

	cout << "大写结果是:\n";

	if (d_2 == 0 && d_1 == 0
		&& d0 == 0 && d1 == 0 && d2 == 0 && d3 == 0
		&& d4 == 0 && d5 == 0 && d6 == 0 && d7 == 0
		&& d8 == 0 && d9 == 0)
	{
		cout << "零圆整\n";
		return 0;
	}

	//十亿
	daxie(d9, zero_flag);
	if (d9)
		cout << "拾";

	//亿
	daxie(d8, zero_flag);
	if (d8 + d9 > 0)
	{
		cout << "亿";
		higher_flag = 1;
	}

	//千万
	zero_flag = (higher_flag && (d6 || d5 || d4)) ? 1 : 0;
	daxie(d7, zero_flag);
	if (d7)
		cout << "仟";

	//百万
	zero_flag = (higher_flag && d7 && (d5 || d4)) ? 1 : 0;
	daxie(d6, zero_flag);
	if (d6)
		cout << "佰";

	//十万
	zero_flag = (higher_flag && (d7 || d6) && d4) ? 1 : 0;
	daxie(d5, zero_flag);
	if (d5)
		cout << "拾";

	//万
	zero_flag = 0;
	daxie(d4, zero_flag);
	if (d7 || d6 || d5 || d4)
		cout << "万";

	higher_flag = higher_flag || (d7 != 0) || (d6 != 0) || (d5 != 0) || (d4 != 0);

	//千
	zero_flag = (higher_flag && (d2 || d1 || d0)) ? 1 : 0;
	daxie(d3, zero_flag);
	if (d3)
		cout << "仟";

	//百
	zero_flag = (higher_flag && d3 && (d1 || d0)) ? 1 : 0;
	daxie(d2, zero_flag);
	if (d2)
		cout << "佰";

	//十
	zero_flag = (higher_flag && (d3 || d2) && d0) ? 1 : 0;
	daxie(d1, zero_flag);
	if (d1)
		cout << "拾";

	//个
	zero_flag = 0;
	daxie(d0, zero_flag);

	higher_flag = higher_flag || (d3 != 0) || (d2 != 0) || (d1 != 0) || (d0 != 0);

	if (higher_flag)
		cout << "圆";
	else
		cout << "零圆";

	if (d_1 == 0 && d_2 == 0)
		cout << "整";
	else
	{
		//角
		daxie(d_1, d_2);
		cout << "角";

		//分
		if (d_2)
		{
			daxie(d_2, 0);
			cout << "分";
		}
		else
			cout << "整";
	}
	cout << endl;

	return 0;
}