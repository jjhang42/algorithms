#include <iostream>
#include <queue>
#include <string>
#include <tuple>

void	printAll(int x, int y, int z, int board[][31][31])
{
	std::cout << "map\n";
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				if (board[i][j][k] != -1)
					std::cout << board[i][j][k];
				else
					std::cout << 'a';
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}

void	printAnswer(int i)
{
	std::cout << "Escaped in " << i << " minute(s).\n";
}

int	solution(void)
{
	int	board[31][31][31] = {0};
	int	lev, x, y;
	std::cin >> lev >> x >> y;
	if (lev == 0 && x == 0 && y == 0)
		return (1);
	int	sec = 0;
	std::queue<std::tuple<int, int, int>>	q;
	std::tuple<int, int, int>				dst;
	for (int i = 0; i < lev; i++)
	{
		for (int j = 0; j < x; j++)
		{
			std::string	str;
			std::cin >> str;
			for (int k = 0; k < y; k++)
			{
				if (str[k] == 'S')
				{
					board[i][j][k] = 0;
					q.push({i, j, k});
				}
				else if (str[k] == 'E')
				{
					board[i][j][k] = 0;
					std::get<0>(dst) = i;
					std::get<1>(dst) = j;
					std::get<2>(dst) = k;
				}
				else if (str[k] == '#')
				{
					board[i][j][k] = -1;
				}
				else
					board[i][j][k] = 0;
			}
		}
	}
	int dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	int	up[2] = {1, -1};
	while (!q.empty())
	{
		std::tuple<int, int, int>	cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	nx = std::get<1>(cur) + dx[i];
			int	ny = std::get<2>(cur) + dy[i];
			int	nz = std::get<0>(cur);
			if (nx < 0 || ny < 0 || x <= nx || y <= ny)
				continue;
			if (board[nz][nx][ny] != 0)
				continue;
			board[nz][nx][ny] = board[std::get<0>(cur)][std::get<1>(cur)][std::get<2>(cur)] + 1;
			if (nz == std::get<0>(dst) && nx == std::get<1>(dst) && ny == std::get<2>(dst))
			{
				printAnswer(board[nz][nx][ny]);
				return (0);
			}
			q.push({nz, nx, ny});
		}
		for (int i = 0; i < 2; i++)
		{
			int	nx = std::get<1>(cur);
			int	ny = std::get<2>(cur);
			int	nz = std::get<0>(cur) + up[i];
			if (nz < 0 || lev <= nz)
				continue;
			if (board[nz][nx][ny] != 0)
				continue;
			board[nz][nx][ny] = board[std::get<0>(cur)][std::get<1>(cur)][std::get<2>(cur)] + 1;
			if (nz == std::get<0>(dst) && nx == std::get<1>(dst) && ny == std::get<2>(dst))
			{
				printAnswer(board[nz][nx][ny]);
				return (0);
			}
			q.push({nz, nx, ny});
		}
	}
	std::cout << "Trapped!" << std::endl;
	return (0);
}

int	main(void)
{
	while (true)
	{
		int	res = solution();
		if (res == 1)
			break ;
	}
	return (0);
}