#include <iostream>
#include <queue>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	x;
	int	y;

	std::cin >> x;
	std::cin >> y;
	int	board[501][501];
	int	visit[501][501];
	int	dx[4] = {1, 0, -1, 0};
	int	dy[4] = {0, 1, 0, -1};

	int	max = 0, num = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int	val;
			std::cin >> val;
			board[i][j] = val;
			visit[i][j] = 0;
		}
	}

	for (int idx1 = 0; idx1 < x; idx1++)
	{
		for (int idx2 = 0; idx2 < y; idx2++)
		{
			if (!(visit[idx1][idx2] == 0 && board[idx1][idx2] == 1))
				continue;
			std::queue<std::pair<int, int> > q;
			visit[idx1][idx2] = 1;
			int	target = 1;
			q.push({idx1,idx2});
			num++;
			while (!q.empty())
			{
				std::pair<int, int>	cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int	nx = dx[i] + cur.first;
					int	ny = dy[i] + cur.second;
					if (nx < 0 || x <= nx || ny < 0 || y <= ny)
						continue;
					if (board[nx][ny] != 1 || visit[nx][ny] != 0)
						continue;
					visit[nx][ny] = 1;
					++target;
					q.push({nx, ny});
				}
			}
			if (max < target)
				max = target;
		}
	}
	std::cout << num << '\n' << max << "\n";
	return (0);
}