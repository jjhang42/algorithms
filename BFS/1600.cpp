#include <iostream>
#include <queue>
#include <tuple>

// void	printAll(int x, int y, int z, int board[][201][201])
// {
// 	std::cout << "\n[print]\n" << std::endl;
// 	for (int k = 0; k < z; k++)
// 	{
// 		std::cout << "level: " << k << std::endl;
// 		for (int i = 0; i < x; i++)
// 		{
// 			for (int j = 0; j < y; j++)
// 			{
// 				if (board[k][i][j] == -1)
// 					std::cout << "!" << " ";
// 				else
// 					std::cout << board[k][i][j] << " ";
// 			}
// 			std::cout << std::endl;
// 		}
// 		std::cout << std::endl;
// 	}
// }

void	inputData(int &k, int &x, int &y, int board[][201][201])
{
	std::cin >> k;
	std::cin >> y >> x;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int	tem;
			std::cin >> tem;
			if (tem == 1)
			{
				for (int l = 0; l < k + 1; l++)
					board[l][i][j] = -1;
			}
		}
	}
}

bool	IsOverFlow(int nx, int ny, int nz, int h, int w, int k)
{
	if (nx < 0 || h <= nx)
		return (true);
	if (ny < 0 || w <= ny)
		return (true);
	if (nz < 0 || k < nz)
		return (true);
	return (false);
}

int IsAnswer(int nx, int ny, int h, int w)
{
	if (nx == h - 1 && ny == w - 1)
		return (true);
	return (false);
}
int	solution(int k, int h, int w, int board[][201][201])
{
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	int	dkx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int	dky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
	std::queue<std::tuple<int, int, int>>	q;
	q.push({0, 0, 0});
	if (IsAnswer(0, 0, h, w))
		return (0);
	if (board[0][0][0] == -1)
		return (-1);
	while (!q.empty())
	{
		int	x = std::get<1>(q.front());
		int	y = std::get<2>(q.front());
		int	z = std::get<0>(q.front());
		q.pop();
		// printAll(h, w, k, board);
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int	ny = y + dy[i];
			int	nz = z;
			if (IsOverFlow(nx, ny, nz, h, w, k) == true)
				continue;
			if (board[nz][nx][ny] != 0)
				continue;
			board[nz][nx][ny] = board[z][x][y] + 1;
			if (IsAnswer(nx, ny, h, w))
				return (board[nz][nx][ny]);
			q.push(std::make_tuple(nz, nx, ny));
		}
		for (int i = 0; i < 8; i++)
		{
			int	nx = x + dkx[i];
			int	ny = y + dky[i];
			int	nz = z + 1;
			if (IsOverFlow(nx, ny, nz, h, w, k))
				continue;
			if (board[nz][nx][ny] != 0)
				continue;
			board[nz][nx][ny] = board[z][x][y] + 1;
			if (IsAnswer(nx, ny, h, w))
				return (board[nz][nx][ny]);
			q.push(std::make_tuple(nz, nx, ny));
		}
	}
	return (-1);
}

int	main(void)
{
	int	board[32][201][201] = {0};
	int	k;
	int	x, y;
	inputData(k, x, y, board);
	std::cout << solution(k, x, y, board);
	return (0);
}