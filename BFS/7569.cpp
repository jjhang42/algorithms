#include <iostream>
#include <queue>
#include <tuple>

void	inputData(int &leftSize, std::tuple<int, int, int> &boxSize, std::queue<std::tuple<int, int, int>> &q, int board[][101][101])
{
	int x;
	int	y;
	int	z;
	std::cin >> y >> x >> z;
	std::get<0>(boxSize) = x;
	std::get<1>(boxSize) = y;
	std::get<2>(boxSize) = z;
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				int	num;
				std::cin >> num;
				board[i][j][k] = num;
				if (num == 1)
					q.push({j, k, i});
				else if (num == 0)
					leftSize++;
			}
		}
	}
}

int	solution(int &leftSize, std::tuple<int, int, int> boxSize, std::queue<std::tuple<int, int, int>> q, int board[][101][101])
{
	int	nx[4] = {0,1,-1,0};
	int	ny[4] = {1,0,0,-1};
	int	nz[2] = {1,-1};
	int	xmax = std::get<0>(boxSize);
	int	ymax = std::get<1>(boxSize);
	int	zmax = std::get<2>(boxSize);
	int day = 0;
	while (1)
	{
		int size = q.size();
		if (q.empty() || !leftSize)
			break;
		while (size--)
		{
			std::tuple<int, int, int>	cur = q.front();
			q.pop();
			for (int idx = 0; idx < 4; idx++)
			{
				int	x = nx[idx] + std::get<0>(cur);
				int	y = ny[idx] + std::get<1>(cur);
				int	z = std::get<2>(cur);
				if (x < 0 || xmax <= x || y < 0 || ymax <= y)
					continue;
				if (board[z][x][y] == 1 || board[z][x][y] == -1)
					continue;
				leftSize--;
				board[z][x][y] = 1;
				q.push({x, y, z});
			}
			for (int idx = 0; idx < 2; idx++)
			{
				int	x = std::get<0>(cur);
				int	y = std::get<1>(cur);
				int	z = nz[idx] + std::get<2>(cur);
				if (z < 0 || zmax <= z)
					continue;
				if (board[z][x][y] == 1 || board[z][x][y] == -1)
					continue;
				leftSize--;
				board[z][x][y] = 1;
				q.push({x, y, z});
			}
		}
		day++;
	}
	if (leftSize != 0)
		return (-1);
	return (day);
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	board[101][101][101] = {0};
	int	x, y, z;
	std::tuple<int, int, int>	boxSize;
	int	leftSize = 0;
	std::queue<std::tuple<int, int, int>>	q;
	inputData(leftSize, boxSize, q, board);
	std::cout << solution(leftSize, boxSize, q, board);
	return (0);
}