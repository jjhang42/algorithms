#include <iostream>
#include <string>
#include <stack>
#include <utility>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::string	str;
	std::cin >> str;
	std::stack<std::pair<char, int>>	s;
	int			res = 0;
	bool		Isopend = false;
	for (int i = 0; str[i] != '\0'; i++)
	{
		char	c = str[i];
		int		cnt;
		if (!s.empty() && c == ')' && s.top().first == '(')
		{
			s.pop();
			if (!s.empty())
			{	
				s.top().first = 'A';
				s.top().second++;
			}
		}
		else if (!s.empty() && c == ')' && s.top().first == 'A')
		{
			cnt = s.top().second;
			res += cnt + 1;
			s.pop();
			if (!s.empty())
			{
				s.top().first = 'A';
				s.top().second += cnt;
			}
		}
		else
			s.push(std::pair<char, int>(c, 0));
	}
	std::cout << res <<"\n";
	return (0);
}