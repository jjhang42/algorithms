#include <iostream>
#include <queue>

void initBoard(int n, char board[][101])
{
	char	c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> c;
			board[i][j] = c;
		}
	}
}

void	printAll(int n, char board[][101])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << '\n';
	}
}
int solution(int n, char board[][101])
{
	int	cnt = 0;
	int	dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	std::queue<std::pair<int, int>>	q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'V')
				continue;
			char c = board[i][j];
			board[i][j] = 'V';
			q.push({i, j});
			cnt++;
			while (!q.empty())
			{
				std::pair<int, int>	cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int	x = cur.first + dx[i];
					int	y = cur.second + dy[i];
					if (x < 0 || y < 0 || n <= x || n <= y)
						continue;
					if (board[x][y] != c)
						continue;
					board[x][y] = 'V';
					q.push({x, y});
				}
			}
		}
	}
	return (cnt);
}

int	getRed(int n, char src[][101])
{
	char	board[101][101];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (src[i][j] == 'B')
				board[i][j] = 'B';
			else
				board[i][j] = 'R';
		}
	}
	return(solution(n, board));
}

int	getNormal(int n, char src[][101])
{
	char	board[101][101];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = src[i][j];
		}
	}
	return(solution(n, board));
}

int	main(void)
{
	char	board[101][101] = {0};
	int	n;

	std::cin >> n;

	initBoard(n, board);
	std::cout << getNormal(n, board) << std::endl;
	std::cout << getRed(n, board) << std::endl;
	return (0);
}