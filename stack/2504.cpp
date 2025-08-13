#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <stdlib.h>

bool isOpened(int i)
{
	if (i == -1)
		return (true);
	if (i == -4)
		return (true);
	return (false);
}

int	initToi(char c)
{
	if (c == '(')
		return (-1);
	if (c == '[')
		return (-4);
	if (c == ')')
		return (-2);
	if (c == ']')
		return (-3);
	return (0);
}

void	error( void )
{
	std::cout << "0\n";
	exit(0);
}

bool IsPair(int open, int close)
{
	if (open == -1 && close == -2)
		return (true);
	if (open == -4 && close == -3)
		return (true);
	return (false);
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::string	str;
	std::stack<long long int>	s;
	std::cin >> str;
	for (size_t i = 0; i < str.size(); i++)
	{
		long long int	cur = initToi(str[i]);
		if (isOpened(cur))
			s.push(cur);
		else
		{
			long long int	num = 1;
			if (!s.empty() && s.top() > 0)
			{
				num = s.top();
				s.pop();
			}
			if (s.empty() || !IsPair(s.top(), cur))
				error();
			s.pop();
			num *= (cur * -1);
			if (!s.empty() && s.top() > 0)
			{
				num += s.top();
				s.pop();
			}
			s.push(num);
		}
	}
	if (s.size() == 1 && s.top() > 0)
		std::cout << s.top() << '\n';
	else
		error();
	return (0);
}