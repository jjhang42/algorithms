#include <iostream>

int	main(void)
{
	int	n;
	std::cin >> n;
	std::cout << static_cast<int>(n * 0.78) << " " << static_cast<int>(n * 0.8 + (n * 0.2) * 0.78) << '\n';
	return(0);
}