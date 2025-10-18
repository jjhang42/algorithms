#include <iostream>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n;

	std::cin >> n;
	for (int i = 0; i < n; n--)
		std::cout << n << '\n';
	return (0);
}