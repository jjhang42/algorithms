#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;

	std::cin >> str;
	int	mod = str.size() % 3;
	if (mod == 1)
		str = "00" + str;
	else if (mod == 2)
		str = "0" + str;

	for (int i = 0; i < str.size(); i += 3)
	{
		int	num = (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0');
		std::cout << num;
	}
	std::cout << std::endl;
	return (0);
}