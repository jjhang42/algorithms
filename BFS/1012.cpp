#include <iostream>
#include <queue>

int	Solution(int a, int b, int num)
{
	int	board[51][51] = {0};
	int	dx[4] = {0, 1, 0, -1};
	int	dy[4] = {1, 0, -1, 0};
	for (int i = 0; i < num; i++)
	{
		int	x, y;
		std::cin >> x >> y;
		board[x][y] = 1;
	}
	std::queue<std::pair<int, int>>	q;	
	int	cnt = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (board[i][j] == 1)
			{
				board[i][j] = 2;
				q.push({i, j});
				cnt++;
			}
			while (!q.empty())
			{
				std::pair<int, int>	cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int	x = cur.first + dx[k];
					int	y = cur.second + dy[k];
					if (x < 0 || y < 0 || a <= x || b <= y)
						continue;
					if (board[x][y] != 1)
						continue;
					board[x][y] = 2;
					q.push({x, y});
				}
			}
		}
	}
	return (cnt);
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int	n;
	std::cin >> n;
	for (int idx1 = 0; idx1 < n; idx1++)
	{
		std::queue<std::pair<int, int>>	q;
		int	a, b, num;
		std::cin >> a >> b >> num;
		std::cout << Solution(a, b, num) << '\n';
	}
	return (0);
}