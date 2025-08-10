#include <iostream>
#include <string>
#include <stack>

int	isOpenedSymbol(char c)
{
	if (c == '(')
		return (1);
	if (c == '{')
		return (2);
	if (c == '[')
		return (3);
	return (0);
}

int	isClosedSymbol(char c)
{
	if (c == ')')
		return (1);
	if (c == '}')
		return (2);
	if (c == ']')
		return (3);
	return (0);
}

int	main(void)
{
	while ( true )
	{
		std::string			str;
		std::stack<char>	s;
		std::getline(std::cin, str);
		if (str == ".")
			break ;
		for (int i = 0; str[i] != '\0'; i++)
		{
			char	c = str[i];
			if (isOpenedSymbol(c))
				s.push(c);
			else if (isClosedSymbol(c))
			{
				if (!s.empty() && isOpenedSymbol(s.top()) == isClosedSymbol(c))
					s.pop();
				else
					s.push(c);
			}
		}
		if (s.empty())
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}
	return (0);
}