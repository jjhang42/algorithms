#include <iostream>
#include <queue>
#include <string>

#define WALL -1
#define FIRE -2
#define EMPTY 0

void	inputdata(int &x, int &y, std::queue<std::pair<int, int>> &man, std::queue<std::pair<int, int>> &fire, int board[][1001])
{
	std::string	str;
	std::cin >> y >> x;
	for (int i = 0; i < x; i++)
	{
		std::cin >> str;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if (str[j] == '@')
				man.push({i, j});
			else if (str[j] == '#')
			{
				board[i][j] = WALL;
			}
			else if (str[j] == '*')
			{
				board[i][j] = FIRE;
				fire.push({i, j});
			}
		}
	}
}

int	solution(int h, int w, std::queue<std::pair<int, int>> man, std::queue<std::pair<int, int>> fire, int board[][1001])
{
	int	nx[4] = {1, 0, 0, -1};
	int	ny[4] = {0, 1, -1, 0};
	if (man.front().first == 0 || man.front().first == h - 1 || man.front().second == 0 || w - 1 == man.front().second)
		return (1);
	while (!man.empty())
	{
		int	manSize = man.size();
		int	fireSize = fire.size();
		int	step = board[man.front().first][man.front().second];
		while (fireSize--)
		{
			std::pair<int, int>	cur = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++)
			{
				int	x = nx[i] + cur.first;
				int	y = ny[i] + cur.second;
				if (x < 0 || h <= x || y < 0 || w <= y)
					continue;
				if (board[x][y] < 0)
					continue;
				board[x][y] = FIRE;
				fire.push({x, y});
			}
		}
		while (manSize--)
		{
			std::pair<int, int>	cur = man.front();
			man.pop();
			for (int i = 0; i < 4; i++)
			{
				int	x = nx[i] + cur.first;
				int	y = ny[i] + cur.second;
				if (x < 0 || y < 0 || h <= x || w <= y)
					return (step + 1);
				if (board[x][y] != 0)
					continue;
				board[x][y] = step + 1;
				man.push({x, y});
			}
		}	
	}
	return (-1);
}

int	main(void)
{
	int	n;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int	board[1001][1001] = {0};
		std::queue<std::pair<int, int>>	man;
		std::queue<std::pair<int, int>>	fire;
		int	h, w;
		inputdata(h, w, man, fire, board);
		int	res = solution(h, w, man, fire, board);
		if (res == -1)
			std::cout << "IMPOSSIBLE\n";
		else
			std::cout << res << '\n';
	}
	return (0);
}