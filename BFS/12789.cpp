#include <iostream>
#include <stack>
#include <queue>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int	n;

	std::cin >> n;
	std::queue<int>	q;
	std::stack<int>	s;
	for (int i = 0; i < n; i++)
	{
		int	tem;
		std::cin >> tem;
		q.push(tem);
	}
	int point = 1;
	while (true)
	{
		if (q.empty() && s.empty())
			break ;
		if (!q.empty() && q.front() == point)
		{
			q.pop();
			point++;
			continue;
		}
		if (!s.empty() && s.top() == point)
		{
			s.pop();
			point++;
			continue;
		}
		if (!q.empty() && q.front() != point)
		{
			s.push(q.front());
			q.pop();
			continue;
		}
		if (q.empty() && !s.empty() && s.top() != point)
		{
			std::cout << "Sad\n";
			return (0);
		}
	}
	std::cout << "Nice\n";
	return (0);
}