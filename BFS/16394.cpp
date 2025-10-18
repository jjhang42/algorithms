#include <iostream>
#include <string>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int	n;
	int	start = 1946;

	std::cin >> n;
	std::cout << n - start << '\n';
	return (0);
}