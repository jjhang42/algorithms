#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	board[101][101] = {0};
	int	x, y, n;
	std::cin >> x >> y >> n;
	for (int i = 0; i < n; i++)
	{
		std::pair<int, int>	point1;
		std::pair<int, int>	point2;
		std::cin >> point1.second >> point1.first;
		std::cin >> point2.second >> point2.first;
		for (int j = point1.first; j < point2.first; j++)
		{
			for (int k = point1.second; k < point2.second; k++)
				board[j][k]++;
		}
	}
	int	dx[4] = {0, 1, -1, 0};
	int	dy[4] = {1, 0, 0, -1};
	int	cnt = 0;
	std::queue<std::pair<int, int>>	q;
	std::vector<int>	v;
	for (int idx1 = 0; idx1 < x; idx1++)
	{
		for (int idx2 = 0; idx2 < y; idx2++)
		{
			if (board[idx1][idx2] != 0)
				continue;
			int	size = 1;
			board[idx1][idx2] = -1;
			q.push({idx1, idx2});
			while (!q.empty())
			{
				std::pair<int, int>	curr = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int	nx = dx[i] + curr.first;
					int	ny = dy[i] + curr.second;
					if (nx < 0 || ny < 0 || x <= nx || y <= ny)
						continue;
					if (board[nx][ny] != 0)
						continue;
					board[nx][ny] = -1;
					q.push({nx, ny});
					size++;
				}
			}
			v.push_back(size);
			cnt++;
		}
	}
	std::sort(v.begin(), v.end());
	std::cout << cnt << '\n';
	for (std::vector<int>::iterator	it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	return (0);
}