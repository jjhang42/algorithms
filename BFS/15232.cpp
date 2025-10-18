#include <iostream>

int	main(void)
{
	int	x, y;
	std::cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			std::cout << "*";
		std::cout << '\n';
	}
	return(0);
}