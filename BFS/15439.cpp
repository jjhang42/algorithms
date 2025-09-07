#include <iostream>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n;

	std::cin >> n;

	std::cout << n * (n - 1) << std::endl;
	return (0);
}