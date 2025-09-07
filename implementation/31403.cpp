#include <iostream>
#include <string>
#include <cstdlib>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::string	a;
	std::string	b;
	std::string	c;

	std::cin >> a >> b >> c;

	std::cout << atoi(a.c_str()) + atoi(b.c_str()) - atoi(c.c_str()) << '\n';
	std::cout << atoi((a + b).c_str()) - atoi(c.c_str());
	return (0);
}