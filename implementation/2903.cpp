#include <iostream>
#include <algorithm>
#include <cmath>

int	main(void)
{
	int	n;
	std::cin >> n;
	int	res = std::pow(2, n);
	res++;
	std::cout << res * res << "\n";
	return (0);
}