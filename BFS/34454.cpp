#include <iostream>

int	main(void)
{
	int	n;
	int	c;
	int	p;
	std::cin >> n >> c >> p;
	if (n <= c * p)
		std::cout << "yes\n";
	else
		std::cout << "no\n";
	return (0);
}