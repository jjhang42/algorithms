#include <iostream>
#include <stack>
#include <vector>

int	main(void)
{
	int	n;
	std::stack<std::pair<long long int, long long int>>	s;
	long long int 				res = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::pair<long long int, long long int>	tem;
		std::cin >> tem.first;
		tem.second = 1;
		while (!s.empty() && tem.first > s.top().first)
		{
			res += s.top().second;
			s.pop();
		}
		if (!s.empty() && tem.first == s.top().first)
		{
			res += s.top().second;
			tem.second += s.top().second;
			s.pop();
		}
		if (!s.empty())
			res++;
		s.push(tem);
	}
	std::cout << res << '\n';
	return (0);
}