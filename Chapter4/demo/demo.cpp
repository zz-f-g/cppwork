#include <iostream>

inline void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int x = 1;
	int y = 2;
	std::cout << "x=" << x << ", y=" << y << std::endl;
	swap(x, y);
	std::cout << "x=" << x << ", y=" << y << std::endl;
	return 0;
}
