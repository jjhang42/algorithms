#include <iostream>
#include <queue>

void	inputData(int &x, int &y, int board[][301], std::queue<std::pair<int, int>>	&q, int &cnt)
{
	std::cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int	input;
			std::cin >> input;
			board[i][j] = input;
			if (input == 0)
				q.push({i, j});
			else
				cnt++;
		}
	}
}

int isSplit(int x, int y, int SrcBoard[][301], int cnt)
{
	int	board[301][301];
	int	res = 0;
	std::pair<int, int>	start = {0, 0};
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (SrcBoard[i][j] == 0)
				board[i][j] = 0;
			else
			{
				if (start.first == 0 && start.second == 0)
				{
					start.first = i;
					start.second = j;
				}
				board[i][j] = 1;
			}
		}
	}
	std::queue<std::pair<int, int>>	q;
	q.push(start);
	board[start.first][start.second] = 2;
	if (start.first != 0 && start.second != 0)
		res++;
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
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
			if (board[nx][ny] == 0 || board[nx][ny] == 2)
				continue;
			board[nx][ny] = 2;
			res++;
			q.push({nx, ny});
		}
	}
	return (cnt - res);
}

int solutions(int x, int y, int board[][301], std::queue<std::pair<int, int>> q, int cnt)
{
	int	time = 0;
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	if (isSplit(x, y, board, cnt) != 0)
		return (0);
	while (!q.empty())
	{
		int	size = q.size();
		while (size--)
		{
			std::pair<int, int>	cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int	nx = dx[i] + cur.first;
				int	ny = dy[i] + cur.second;
				if (nx < 0 || x <= nx || ny < 0 || y <= ny)
					continue;
				if (board[nx][ny] == 0)
					continue;
				board[nx][ny]--;
				if (board[nx][ny] == 0)
				{
					q.push({nx, ny});
					cnt--;
				}
			}
			bool flag = false;
			for (int i = 0; i < 4; i++)
			{
				int	nx = cur.first + dx[i];
				int	ny = cur.second + dy[i];
				if (nx < 0 || x <= nx || ny < 0 || y <= ny)
					continue;
				if (board[nx][ny] != 0)
					flag = true;
			}
			if (flag)
				q.push(cur);
		}
		time++;
		if (isSplit(x, y, board, cnt) != 0)
			return (time);
	}
	return (0);
}

int	main(void)
{
	int	board[301][301];
	int	x, y, cnt = 0;
	std::queue<std::pair<int, int>>	q;
	inputData(x, y, board, q, cnt);
	std::cout << solutions(x, y, board, q, cnt) << std::endl;
	return (0);
}