#include <iostream>
#include <string>
#include <queue>
#include <tuple>

void	initBoard(std::queue<std::tuple<int, int, int>> &q, int &x, int &y, int board[][1001][2])
{
	std::cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		std::string	str;
		std::cin >> str;
		for (int j = 0; j < y; j++)
		{
			if (str[j] == '1')
			{
				board[i][j][0] = -1;
				board[i][j][1] = -1;
			}
		}
	}
	std::tuple<int, int, int>	front;
	std::get<0>(front) = 0;
	std::get<1>(front) = 0;
	std::get<2>(front) = 1;
	board[0][0][1] = 1;
	q.push(front);
}

int	solution(std::queue<std::tuple<int, int, int>>	&q, int &x, int &y, int board[][1001][2])
{
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	if (x == 1 && y == 1)
		return (1);
	while (!q.empty())
	{
		std::tuple<int, int, int>	cur = q.front();
		q.pop();
		int	curX = std::get<0>(cur);
		int	curY = std::get<1>(cur);
		int	curStep = std::get<2>(cur);
		for (int i = 0; i < 4; i++)
		{
			int	nx = std::get<0>(cur) + dx[i];
			int	ny = std::get<1>(cur) + dy[i];
			int	times = std::get<2>(cur);
			if (nx < 0 || x <= nx || ny < 0 || y <= ny)
				continue;
			if (board[nx][ny][times] != 0)
			{
				if (board[nx][ny][times] == -1 && times == 1)
						times = 0;
				else
					continue;
			}
			board[nx][ny][times] = board[curX][curY][curStep] + 1;
			if (nx == x - 1 && ny == y - 1)
				return (board[nx][ny][times]);
			q.push({nx, ny, times});
		}
	}
	return (-1);
}

int	main(void)
{
	int	board[1001][1001][2] = {0};
	std::queue<std::tuple<int, int, int>>	q;
	int	x, y;
	initBoard(q, x, y, board);
	std::cout << solution(q, x, y, board) << "\n";
	return (0);
}
