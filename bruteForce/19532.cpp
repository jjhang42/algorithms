#include <iostream>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5

bool	formula(int x, int y, int a, int b, int c)
{
	if (x * a + y * b == c)
		return (true);
	return (false);
}

//c + f = x(a+d) + y(b+e);
int	main(void)
{
	int	num[6];
	for (int i = 0; i < 6; i++)
	{
		std::cin >> num[i];
	}
	
	for (int x = -999; x < 1000; x++)
	{
		for (int y = -999; y < 1000; y++)
		{
			if (formula(x, y, num[A], num[B], num[C]) && formula(x, y, num[D], num[E], num[F]))
			{
				std::cout << x << " " << y << std::endl;
			}
		}
	}
	return (0);
}