#include <iostream>
#include <string>
#include <queue>

void	Inputdata(int &x, int &y, int visit[][1001], std::queue<std::pair<int, int>> &man, std::queue<std::pair<int, int>> &fire)
{
	std::cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		std::string	input;
		std::cin >> input;
		for (int j = 0; j < y; j++)
		{
			if (input[j] == '#')
				visit[i][j] = -1;
			else if (input[j] == 'F')
			{
				fire.push({i, j});
				visit[i][j] = -2;
			}
			else if (input[j] == 'J')
			{
				man.push({i, j});
				visit[i][j] = 1;
			}
			else
				visit[i][j] = 0;
		}
	}
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int	x = 0;
	int	y = 0;
	int	visit[1001][1001];
	std::queue<std::pair<int, int>>	man;
	std::queue<std::pair<int, int>>	fire;
	Inputdata(x, y, visit, man, fire);
	int	dx[4] = {1, 0, 0, -1};
	int	dy[4] = {0, 1, -1, 0};
	
	if (man.front().first == 0 || man.front().second == 0 || man.front().first == x - 1 || man.front().second == y - 1)
	{
		std::cout << "1\n";
		return (0);
	}
	while (!man.empty())
	{
		int	fireSize = fire.size();
		while (fireSize--)
		{
			std::pair<int, int> cur = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++)
			{
				int	nx = cur.first + dx[i];
				int	ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || x <= nx || y <= ny)
					continue;
				if (visit[nx][ny] != 0)
					continue;
				visit[nx][ny] = -2;
				fire.push({nx, ny});
			}
		}
		int	manSize = man.size();
		while (manSize--)
		{
			std::pair<int, int>	cur = man.front();
			man.pop();
			for (int i = 0; i < 4; i++)
			{
				int	nx = cur.first + dx[i];
				int	ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || x <= nx || y <= ny)
					continue;
				if (visit[nx][ny] != 0)
					continue;
				visit[nx][ny] = visit[cur.first][cur.second] + 1;
				if (nx == 0 || ny == 0 || nx == x - 1 || ny == y - 1)
				{
					std::cout << visit[nx][ny] << '\n';
					return (0);
				}
				man.push({nx, ny});
			}
		}
	}
	std::cout << "IMPOSSIBLE\n";
	return (0);
}