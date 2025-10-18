#include <iostream>
#include <climits>
#include <queue>
#include <vector>

typedef	std::queue<std::pair<int, int>>	queue;
#define	VISIT	1
#define	BOARD	0

void	inputData(int &n, int board[][101][101])
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int	tem;
			std::cin >> tem;
			if (tem == 1)
				board[0][i][j] = -1;
			else
				board[0][i][j] = 0;
		}
	}
}

bool	IsOverFlow(int n, int nx, int ny)
{
	if (nx < 0 || n <= nx || ny < 0 || n <= ny)
		return (true);
	return (false);
}

void	printAll(int n, int board[][101][101])
{
	std::cout << "\n[PRINT]\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << board[0][i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void	printMov(int lv, int n, int board[][101][101])
{
	std::cout << "\n[PRINT"<< lv << "]\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << board[VISIT][i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void	setupData(int n, std::vector<queue>	&v, int board[][101][101])
{
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	int	lv = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[0][i][j] != -1)
				continue;
			queue	q;
			queue	vData;
			lv++;
			q.push({i, j});
			board[BOARD][i][j] = lv;
			while (!q.empty())
			{
				std::pair<int, int>	cur = q.front();
				q.pop();
				int	flag = false;
				for (int k = 0; k < 4; k++)
				{
					int	nx = dx[k] + cur.first;
					int	ny = dy[k] + cur.second;
					if (IsOverFlow(n, nx, ny))
						continue;
					if (board[BOARD][nx][ny] == 0)
						flag = true;
				}
				if (flag)
					vData.push(cur);
				for (int k = 0; k < 4; k++)
				{
					int	nx = dx[k] + cur.first;
					int	ny = dy[k] + cur.second;
					if (IsOverFlow(n, nx, ny))
						continue;
					if (board[BOARD][nx][ny] != -1)
						continue;
					board[BOARD][nx][ny] = lv;
					q.push({nx, ny});
				}
			}
			v.push_back(vData);
		}
	}
}

void	initVisitBoard(int board[][101][101])
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			board[VISIT][i][j] = 0;
		}
	}
}

int	solutions(int n, std::vector<queue> v, int board[][101][101])
{
	int	dx[4] = {0, 0, 1, -1};
	int	dy[4] = {1, -1, 0, 0};
	int	min = INT_MAX;
	while (v.size())
	{
		queue	q = v[v.size() - 1];
		v.pop_back();
		initVisitBoard(board);
		int	lv = board[BOARD][q.front().first][q.front().second];
		while (!q.empty())
		{
			std::pair<int, int>	cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int	nx = dx[i] + cur.first;
				int	ny = dy[i] + cur.second;
				if (IsOverFlow(n, nx, ny))
					continue;
				if (board[BOARD][nx][ny] != 0 && board[BOARD][nx][ny] != lv)
				{
					if (min > board[VISIT][cur.first][cur.second])
						min = board[VISIT][cur.first][cur.second];
					queue	empty;
					q.swap(empty);
					break ;
				}
				if (board[VISIT][nx][ny] != 0 || board[BOARD][nx][ny] == lv)
					continue;
				board[VISIT][nx][ny] = board[VISIT][cur.first][cur.second] + 1;
				q.push({nx, ny});
			}
		}
	}
	return (min);
}

int	main(void)
{
	int	n;
	int	board[2][101][101] = {0};
	std::vector<queue>	v;
	inputData(n, board);
	setupData(n, v, board);
	std::cout << solutions(n, v, board) << '\n';
	return (0);
}