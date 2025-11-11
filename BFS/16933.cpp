#include <iostream>
#include <queue>
#include <tuple>
#include <string>

int	board[2][11][1001][1001];
int	visit[1001][1001];
int	x, y, z;
#define	DAY 0
#define	NIGHT 1

void	inputData(void)
{
	std::cin >> x >> y >> z;
	for (int i = 0; i < x; i++)
	{
		std::string	tem;
		std::cin >> tem;
		for (int j = 0; j < y; j++)
		{
			if (tem[j] == '1')
			{
				board[0][0][i][j] = -1;
			}
		}
	}
}

void	printLayer(int Time, int lv)
{
	std::cout << "\nlv: " << lv << " Time: " << Time << std::endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (board[Time][lv][i][j] != -1)
				std::cout << board[Time][lv][i][j];
			else
				std::cout << "A";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

bool	IsOverFlow(int nx, int ny, int nz)
{
	if (nx < 0 || x <= nx)
		return (true);
	if (ny < 0 || y <= ny)
		return (true);
	if (nz < 0 || z < nz)
		return (true);
	return (false);
}

int	solution( void )
{
	if (x == 1 && y == 1)
		return (1);
	int	dx[4] = {1, -1, 0, 0};
	int	dy[4] = {0, 0, 1, -1};
	std::queue<std::tuple<int, int, int, int>>	q;
	//day | x | y | z
	q.push({0, 0, 0, 0});
	board[0][0][0][0] = 1;
	while (!q.empty())
	{
		bool	cTime	= std::get<0>(q.front());
		int		cx		= std::get<1>(q.front());
		int		cy		= std::get<2>(q.front());
		int		cz		= std::get<3>(q.front());
		q.pop();
		int	flag = 0;
		for (int i = 0; i < 4; i++)
		{
			bool	nTime 	= !cTime;
			int		nx		= cx + dx[i];
			int		ny		= cy + dy[i];
			int		nz		= cz;
			if (IsOverFlow(nx, ny, nz))
				continue;
			if (board[0][0][nx][ny] == -1)
			{
				if (cTime == NIGHT)
					flag = 1;
				if (nz < z && !flag)
					nz++;
				else
					continue;
			}
			if (board[nTime][nz][nx][ny] != 0)
				continue;
			board[nTime][nz][nx][ny] = board[cTime][cz][cx][cy] + 1;
			if (nx == x - 1 && ny == y - 1)
				return (board[nTime][nz][nx][ny]);
			q.push({nTime, nx, ny, nz});
		}
		if (flag)
		{
			board[!cTime][cz][cx][cy] = board[cTime][cz][cx][cy] + 1;
			q.push({!cTime, cx, cy, cz});
		}
	}
	return (-1);
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	inputData();
	std::cout << solution();
	return (0);
}