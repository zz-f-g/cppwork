#include <iostream>
using namespace std;

int main()
{
	char c;
	cout << "Whether can we input ascii code(from 0 - 127):" << endl;
	cin >> c;
	cout << "c = " << c << endl;
	return 0;
}
/*
	cout << "Whether can we input octal or hexdecimal number(like \\*** or \\x**):" << endl;
	cin >> c;
	cout << "c = " << c << endl;
	cout << "Input ascii code and convert it to character:" << endl;
	int asc;
	cin >> asc;
	c = (char)asc;
	cout << "c = " << c << endl;
int main()
{
	char c;
	cout << "Input a character(like a letter 'A'):" << endl;
	cin >> c;
	cout << "c = " << c << endl;
	cout << "ord(c) = " << c+0 << endl;

	cout << "Whether can input escape character (like \\n, \\b, \\r):" << endl;
	cin >> c;
	cout << "c = " << c << endl;
	return 0;
}
*/