#include <iostream>
#include <queue>
#include <climits>
#include <tuple>

void	initBoard(int x, int y, int k, int board[][1001][1001])
{

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int	tem;
			std::cin >> tem;
			if (tem == 1)
			{
				for (int a = 0; a < k; a++)
					board[a][i][j] = -2;
			}
			else
			{
				for (int a = 0; a < k; a++)
					board[a][i][j] = -1;
			}
		}
	}
}

bool	IsExit(int x, int y, int nx, int ny)
{
	if (x == nx - 1 && y == ny - 1)
		return (true);
	return (false);
}

bool	IsOverFlow(int x, int y, int z, int nx, int ny, int nz)
{
	if (nx < 0 || x <= nx)
		return (true);
	if (ny < 0 || y <= ny)
		return (true);
	if (nz < 0 || z <= nz)
		return (true);
	return (false);
}

int	solution(int x, int y, int k, int board[][1001][1001])
{
	if (x == 1 && y == 1)
		return (0);

	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	std::queue<std::tuple<int, int, int>>	q;
	q.push({0, 0, 0});
	board[0][0][0] = 0;
	while (!q.empty())
	{
		int	x = std::get<0>(q.front());
		int	y = std::get<1>(q.front());
		int	z = std::get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	nx = x + dx[i];
			int	ny = y + dy[i];
			int	nz = z;
			if (IsOverFlow(x, y, z, nz, ny, nz))
				continue;
			if (z < k && board )
		}
	}
	return (-1);
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int	board[11][1001][1001];
	int		k, x, y;
	std::cin >> x >> y >> k;
	initBoard(x, y, k, board);
	std::cout << solution(x, y, k, board);
	return (0);
}