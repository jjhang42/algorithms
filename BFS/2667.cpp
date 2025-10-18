#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

int	main(void)
{
	int	board[26][26] = {0};
	int	n;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	str;
		std::cin >> str;
		for (int j = 0; str[j] != '\0'; j++)
		{
			board[i][j] = str[j] - '0';
		}
	}

	int	dx[4] = {0, 1, -1, 0};
	int	dy[4] = {1, 0, 0, -1};

	int	cnt = 0;
	std::queue<std::pair<int, int>>	q;
	std::vector<int>	v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 1)
				continue;
			int	size = 1;
			q.push({i, j});
			board[i][j] = 2;
			cnt++;
			while (!q.empty())
			{
				std::pair<int, int>	cur = q.front();
				q.pop();
				for (int curIdx = 0; curIdx < 4; curIdx++)
				{
					int	nx = cur.first + dx[curIdx];
					int	ny = cur.second + dy[curIdx];
					if (nx < 0 || ny < 0 || n <= nx || n <= ny)
						continue;
					if (board[nx][ny] != 1)
						continue;
					q.push({nx, ny});
					board[nx][ny] = 2;
					size++;
				}
			}
			v.push_back(size);
		}
	}
	std::sort(v.begin(), v.end());
	std::cout << cnt << '\n';
	for (std::vector<int>::iterator	it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << '\n';
	}
	return(0);
}