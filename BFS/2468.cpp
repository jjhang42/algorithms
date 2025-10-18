#include <iostream>
#include <queue>

int	solution(int water, int n, int src[][101])
{
	int	board[101][101];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (src[i][j] <= water)
				board[i][j] = -1;
			else
				board[i][j] = 0;
		}
	}

	std::queue<std::pair<int, int>>	q;
	int	dx[4] = {0, -1, 1, 0};
	int	dy[4] = {-1, 0, 0, 1};
	int	res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 0)
				continue;
			q.push({i, j});
			board[i][j] = 1;
			while (!q.empty())
			{
				std::pair<int, int>	cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int	nx = dx[k] + cur.first;
					int	ny = dy[k] + cur.second;
					if (nx < 0 || ny < 0 || n <= nx || n <= ny)
						continue;
					if (board[nx][ny] != 0)
						continue;
					q.push({nx, ny});
					board[nx][ny] = 1;
				}
			}
			res++;
		}
	}
	return (res);
}

int	main(void)
{
	int	board[101][101] = {0};
	int	min = 100, max = 0;
	int	n;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int	tem;
			std::cin >> tem;
			board[i][j] = tem;
			if (tem < min)
				min = tem;
			if (tem > max)
				max = tem;
		}
	}
	if (min == max)
		min--;
	int	cnt = 0;
	while (min < max)
	{
		int tem;
		tem = solution(min, n, board);
		if (tem > cnt)
			cnt = tem;
		min++;
	}
	std::cout << cnt << '\n';
	return (0);
}