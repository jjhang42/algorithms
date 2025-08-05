#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

void	insert_firstVal(std::stack<std::pair<int, int>> &s, std::vector<int> &out)
{
	std::pair<int, int>	first;

	std::cin >> first.first;
	first.second = 1;
	s.push(first);
	out[0] = 0;
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int								n;
	std::stack<std::pair<int, int>>	s;
	std::pair<int, int>				curTower;
	std::cin >> n;

	std::vector<int>				out(n);
	insert_firstVal(s, out);
	for (int i = 1; i < n; i++)
	{
		std::cin >> curTower.first;
		curTower.second = i + 1;
		while (s.size() > 1 && curTower.first > s.top().first)
			s.pop();
		if (s.top().first >= curTower.first)
		{
			out[i] = s.top().second;
		}
		else
			out[i] = 0;
		s.push(curTower);
	}
	for (std::vector<int>::iterator it = out.begin(); it != out.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != out.end())
			std::cout << " ";
	}
	return (0);
}