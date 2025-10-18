#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;

	std::cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (std::isupper(str[i]))
			std::cout << static_cast<char>(str[i] + 32);
		else
			std::cout << static_cast<char>(str[i] - 32);
	}
	std::cout << '\n';
	return(0);
}