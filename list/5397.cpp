#include <iostream>
#include <string>
#include <list>

int	main( void )
{
	std::string	str;
	int			n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> str;
		std::list<char>	lst;
		std::list<char>::iterator	it = lst.begin();
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '<')
			{
				if (it != lst.begin())
					--it;
			}
			else if (str[i] == '>')
			{
				if (it != lst.end())
					++it;
			}
			else if (str[i] == '-')
			{
				if (it != lst.begin())
				{
					std::list<char>::iterator	tem = it;
					--it;
					lst.erase(it);
					it = tem;
				}
			}
			else
				lst.insert(it, str[i]);
		}
		for (std::list<char>::iterator it2 = lst.begin(); it2 != lst.end(); ++it2)
		{
			std::cout << *it2;
		}
		std::cout << "\n";
	}
	return (0);
}