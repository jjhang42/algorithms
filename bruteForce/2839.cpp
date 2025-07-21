#include <iostream>

int	main(void)
{
	int	N;
	int	x;
	int	y;
	std::cin >> N;
	int	minBags = N;

	for (x = N / 5; 0 <= x; x--)
	{
		int	tem = N - x * 5;
		if (tem % 3 == 0)
		{
			y = tem / 3;
			break;
		}
	}
	if ((x * 5 + y * 3) != N)
		minBags = -1;
	else
		minBags = x + y;
	std::cout << minBags;
	return (0);
}