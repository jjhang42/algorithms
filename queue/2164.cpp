#include <iostream>
#include <queue>

int	main(void)
{
	int	n;
	std::queue<int>	q;

	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	while (q.size() != 1)
	{
		q.pop();
		q.emplace(q.front());
		q.pop();
	}

	std::cout << q.front();
	return (0);
}