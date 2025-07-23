#include <iostream>
#include <cstring>
int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int	num = 1;
	int	arr[10];

	std::memset(arr, 0, sizeof(int) * 10);
	for (int i = 0; i < 3; i++)
	{
		int	tem;
		std::cin >> tem;
		num *= tem;
	}
	while (num != 0)
	{
		int	tem = num % 10;
		arr[tem]++;
		num /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << '\n';
	}
	return (0);
}