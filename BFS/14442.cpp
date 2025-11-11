#include <iostream>
#include <queue>
#include <climits>
#include <tuple>
#include <string>

int		board[11][1001][1001];

void	initBoard(int &x, int &y)
{
	for (int i = 0; i < x; i++)
	{
		std::string	tem;
		std::cin >> tem;
		for (int j = 0; j < y; j++)
		{
			if (tem[j] == '1')
				board[0][i][j] = -1;
			else
				board[0][i][j] = 0;
		}
	}
}

bool	IsOverFlow(int x, int y, int z, int nx, int ny, int nz)
{
	if (nx < 0 || x <= nx)
		return (true);
	if (ny < 0 || y <= ny)
		return (true);
	if (nz < 0 || z < nz)
		return (true);
	return (false);
}

// void	printlayer(int x, int y, int z)
// {
// 	std::cout << '\n' << "layer: " << z << '\n';
// 	for (int i = 0; i < x; i++)
// 	{
// 		for (int j = 0; j < y; j++)
// 		{
// 			std::cout << board[z][i][j];
// 		}
// 		std::cout << '\n';
// 	}
// }

int	solution(int x, int y, int z)
{
	if (x == 1 && y == 1)
		return (1);
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	std::queue<std::tuple<int, int, int>>	q;
	q.push({0, 0, 0});
	board[0][0][0] = 1;
	while (!q.empty())
	{
		int	cx = std::get<0>(q.front());
		int	cy = std::get<1>(q.front());
		int	cz = std::get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	nx = cx + dx[i];
			int	ny = cy + dy[i];
			int	nz = cz;
			if (IsOverFlow(x, y, z, nx, ny, nz))
				continue;
			if (board[0][nx][ny] != 0)
			{
				if (nz < z)
					nz++;
				else
					continue;
			}
			if (board[nz][nx][ny] == 0)
			{
				board[nz][nx][ny] = board[cz][cx][cy] + 1;
				if (nx == x - 1 && ny == y - 1)
				{
					// printlayer(x, y, 0);
					// printlayer(x, y, nz);
					return (board[nz][nx][ny]);
				}
				q.push({nx, ny, nz});
			}
		}
	}
	return (-1);
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int		x, y, z;
	std::cin >> x >> y >> z;
	initBoard(x, y);
	std::cout << solution(x, y, z);
	return (0);
}