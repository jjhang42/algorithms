#include <iostream>
#include <string>
#include <queue>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	x;
	int	y;

	std::cin >> x;
	std::cin >> y;

	int	board[501][501];
	int	visit[501][501];
	int	dx[5] = {0, 1, 0, -1};
	int	dy[5] = {1, 0, -1, 0};
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int	num;
			std::cin >> num;
			board[i][j] = num;
			visit[i][j] = 0;
		}
	}

	int	max = 0;
	int	num = 0;
	int	curNum = 0;
	for (int i)

	std::cout << max << '\n' << num << '\n';
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << visit[i][j];
		}
		std::cout << "\n";
	}
	return (0);
}