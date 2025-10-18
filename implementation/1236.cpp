#include <iostream>

int	main(void)
{
	int	n;

	std::cin >> n;
	for (; n; n--)
	{
		for (int i = n; i; i--)
			std::cout << "*";
		std::cout << std::endl;
	}
	return (0);
}