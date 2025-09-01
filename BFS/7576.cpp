#include <iostream>
#include <queue>

int	main(void)
{
	int	x;
	int	y;
	int	board[1001][1001];
	int	visit[1001][1001];
	std::cin >> y >> x;
	int	minuscnt = 0;
	int	cnt = 0;
	std::queue<std::pair<int, int>>	q;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int	input;
			std::cin >> input;
			board[i][j] = input;
			visit[i][j] = 0;
			if (input == 1)
			{
				q.push({i, j});
				visit[i][j] = 0;
				cnt++;
			}
			if (input == -1)
			{
				visit[i][j] = -1;
				++minuscnt;
			}
		}
	}
	int	dx[4] = {0, 1, -1, 0};
	int	dy[4] = {1, 0, 0, -1};
	int	day = 0;
	while (!q.empty())
	{
		std::pair<int, int>	cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	nx = cur.first + dx[i];
			int	ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || x <= nx || y <= ny)
				continue;
			if (visit[nx][ny] != 0 || board[nx][ny] != 0)
				continue;
			q.push({nx, ny});
			visit[nx][ny] = visit[cur.first][cur.second] + 1;
			if (day < visit[nx][ny])
				day = visit[nx][ny];
			cnt++;
		}
	}
	if (x * y == cnt + minuscnt)
		std::cout << day << '\n';
	else
		std::cout << -1 << '\n';
	return (0);
}