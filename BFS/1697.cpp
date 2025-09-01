#include <iostream>
#include <queue>

int	main(void)
{
	int	n, k;
	int	map[100001] = {0};

	std::cin >> n >> k;

	if (n == k)
	{
		std::cout << "0\n";
		return (0);
	}
	std::queue<int>	q;
	q.push(n);
	map[n] = 0;
	while (!q.empty())
	{
		int	size = q.size();
		while (size--)
		{
			int	x = q.front();
			int	time = map[x] + 1;
			q.pop();
			int	next = x - 1;
			if (0 <= next && next <= 100000 && map[next] == 0)
			{
				if (next == k)
				{
					std::cout << time << '\n';
					return (0);
				}
				map[next] = time;
				q.push(next);
			}
			next = x + 1;
			if (0 <= next && next <= 100000 && map[next] == 0)
			{
				if (next == k)
				{
					std::cout << time << '\n';
					return (0);
				}
				map[next] = time;
				q.push(next);
			}
			next = x * 2;
			if (0 <= next && next <= 100000 && map[next] == 0)
			{				
				if (next == k)
				{
					std::cout << time << '\n';
					return (0);
				}
				map[next] = time;
				q.push(next);
			}
		}
	}
	return (0);
}