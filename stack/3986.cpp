#include <iostream>
#include <string>
#include <stack>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n;
	int	cnt = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	str;
		std::cin >> str;
		std::stack<char> s;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (!s.empty() && str[i] == s.top())
				s.pop();
			else
				s.push(str[i]);
		}
		if (s.empty())
			cnt++;
	}
	std::cout << cnt << '\n';
	return (0);
}