#include <iostream>
#include <list>
#include <string>

int	main(void)
{
	std::string		str;
	std::list<char>	lst;
	int				M;
	std::list<char>::iterator	curr;
	std::cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
		lst.push_back(str[i]);
	curr = lst.end();
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		str = "";
		std::cin >> str;
		if (str[0] == 'L' && curr != lst.begin())
				--curr;
		else if (str[0] == 'D' && curr != lst.end())
				++curr;
		else if (str[0] == 'B' && curr != lst.begin())
		{
			std::list<char>::iterator	tem = curr;
			--curr;
			lst.erase(curr);
			curr = tem;
		}
		else if (str[0] == 'P')
		{
			std::cin >> str;
			lst.insert(curr, str[0]);
		}
	}
	for (std::list<char>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it;
	}
	return (0);
}