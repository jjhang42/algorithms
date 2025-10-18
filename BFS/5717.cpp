#include <iostream>

int	main(void)
{
	int	x = 1, y = 1;
	while (x || y)
	{
		std::cin >> x >> y;
		if (x + y)
			std::cout << x + y << '\n';
	}
	return (0);
}