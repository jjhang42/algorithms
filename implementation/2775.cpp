#include <iostream>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int	n;

	std::cin >> n;
	int	arr[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == 0)
				arr[i][j] = j + 1;
			else if (j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int	lev;
		int	room;
		std::cin >> lev;
		std::cin >> room;
		std::cout << arr[lev][--room] << "\n";
	}
	return (0);
}