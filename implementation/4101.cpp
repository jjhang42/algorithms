#include <iostream>

int	main(void)
{
	while (true)
	{
		int	x, y;
		std::cin >> x >> y;
		if (x == 0 && y == 0)
			return (0);
		if (x > y)
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
	return (0);
}