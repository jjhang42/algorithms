#include <iostream>

int	main(void)
{
	int	n;
	std::cin >> n;
	std::cout << (n / 5) + (1) * (n % 5 != 0);
	return (0);
}