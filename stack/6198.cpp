#include <iostream>
#include <stack>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	n;
	long long int	res = 0;
	std::stack<long long int>	s;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long int	tem;
		std::cin >> tem;
		if (s.size() != 0 && tem >= s.top())
		{
			while (s.size() != 0 && tem >= s.top())
				s.pop();
		}
		if (s.size() != 0)
			res += (s.size());
		s.push(tem);
	}
	std::cout << res;
	return (0);
}