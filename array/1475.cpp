#include <iostream>
#include <cstring>

int	main(void)
{
	int	num[10];
	int	target;
	int	max = 0;

	std::memset(num, 0, sizeof(int) * 10);
	std::cin >> target;

	for (int i = target; i != 0; i /= 10)
	{
		int	tem = i % 10;
		num[tem]++;
	}
	num[6] += num[9];
	num[9] = num[6] / 2 + num[6] % 2;
	num[6] /= 2;
	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
			max = num[i];
	}
	std::cout << max;
	return (0);
}