#include <iostream>
#include <string>
#include <queue>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int	n;
	int	m;
	int	arr[101][101];
	int	vis[101][101];
	int	dx[4] = {0, -1, 1, 0};
	int dy[4] = {-1, 0, 0, 1};
	std::cin >> n;
	std::cin >> m;
	for (int i = 0; i < n; i++)
	{
		std::string	input;
		std::cin >> input;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = input[j] - '0';
			vis[i][j] = 0;
		}
	}

	std::queue<std::pair<int, int> >	q;

	q.push({0,0});
	vis[0][0] = 1;
	while (!q.empty())
	{
		std::pair<int, int>	dst = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	nx = dx[i] + dst.first;
			int	ny = dy[i] + dst.second;
			if (nx < 0 || ny < 0 || n <= nx || m <= ny)
				continue;
			if (vis[nx][ny] != 0 || arr[nx][ny] != 1)
				continue;
			vis[nx][ny] = vis[dst.first][dst.second] + 1;
			q.push({nx, ny});
		}
	}
	std::cout << vis[n - 1][m - 1] << std::endl;
	return (0);
}