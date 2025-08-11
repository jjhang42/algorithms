#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	str;
		std::stack<char>	s;

		std::cin >> str;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if (!s.empty() && str[j] == ')' && s.top() == '(')
				s.pop();
			else
				s.push(str[j]);
		}
		if (s.empty())
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	return (0);
}