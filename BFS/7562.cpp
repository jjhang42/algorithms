#include <iostream>
#include <queue>

void	inputdata(int &n, std::queue<std::pair<int, int>> &src, std::pair<int, int> &dst, int board[][301])
{
	std::cin >> n;
	int	x, y;
	std::cin >> x >> y;
	src.push({x, y});
	std::cin >> dst.first >> dst.second;
}

int	solution(int max, std::queue<std::pair<int, int>> src, std::pair<int, int> dst, int board[301][301])
{
	int	nx[4] = {-2, -1, +2, +1};
	int	ny[4] = {+1, +2, +1, +2};
	if (src.front() == dst)
		return (0);
	while (!src.empty())
	{
		std::pair<int, int> cur = src.front();
		int	curStep = board[cur.first][cur.second];
		src.pop();
		for (int i = 0; i < 4; i++)
		{
			int	x = nx[i] + cur.first;
			int	y = ny[i] + cur.second;
			if (x < 0 || max <= x || y < 0 || max <= y)
				continue;
			if (board[x][y] != 0)
				continue;
			if (x == dst.first && y == dst.second)
				return (curStep + 1);
			board[x][y] = curStep + 1;
			src.push({x, y});
		}
		for (int i = 0; i < 4; i++)
		{
			int	x = (nx[i] * -1) + cur.first;
			int	y = (ny[i] * -1) + cur.second;
			if (x < 0 || max <= x || y < 0 || max <= y)
				continue;
			if (board[x][y] != 0)
				continue;
			if (x == dst.first && y == dst.second)
				return (curStep + 1);
			board[x][y] = curStep + 1;
			src.push({x, y});
		}
	}
	return (0);
}

int	main(void)
{
	int	time;
	std::cin >> time;
	for (int i = 0; i < time; i++)
	{
		std::queue<std::pair<int, int>> src;
		std::pair<int, int>	dst;
		int	board[301][301] = {0};
		int	n = 0;
		inputdata(n, src, dst, board);
		std::cout << solution(n, src, dst, board) << '\n';
	}
	return (0);
}