#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;

	std::cin >> str;
	for (std::string::iterator	it = str.begin(); it != str.end(); ++it)
	{
		if ('a' <= *it && *it <= 'z')
			std::cout << static_cast<char>(*it - 32);
	}
	std::cout << '\n';
	return (0);
}