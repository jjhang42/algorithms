#include <iostream>

int	main(void)
{
	char	c;
	std::cin >> c;
	if (c == 'n' || c == 'N')
		std::cout << "Naver D2" << std::endl;
	else
		std::cout << "Naver Whale" << std::endl;
	return (0);
}