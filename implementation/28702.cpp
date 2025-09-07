#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

int	main(void)
{
	std::string		str[3];
	long long int	num;
	bool			flag = false;
	for (int i = 0; i < 3; i++)
	{
		std::cin >> str[i];
		if (!flag && isdigit(str[i][0]))
		{
			num = std::atoi(str[i].c_str());
			flag = true;
		}
		else if (flag)
			num++;
	}
	num++;
	if (num % 3 == 0 && num % 5 == 0)
		std::cout << "FizzBuzz";
	else if (num % 3 == 0 && num % 5 != 0)
		std::cout << "Fizz";
	else if (num % 3 != 0 && num % 5 == 0)
		std::cout << "Buzz";
	else
		std::cout << num;
	return (0);
}