#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

int	IsDoomNumber(std::string dst)
{
	std::string	doom = "666";
	const char	*answer;
	answer = strstr(dst.c_str(), doom.c_str());

	if (answer == NULL)
		return (0);
	return (1);
}

int	main(void)
{
	int	num = 0;
	int	check = 0;
	int	N;
	std::cin >> N;
	while ( true )
	{
		std::ostringstream	tem;
		tem << num;
		check += IsDoomNumber(tem.str());
		if (check == N)
		{
			std::string	res = tem.str();
			std::cout << res;
			break;
		}
		num++;
	}
	return (0);
}