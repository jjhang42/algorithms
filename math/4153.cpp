#include <iostream>
#include <algorithm>
#include <cmath>

void	maxToz(long long int num[])
{
	int	i = 0;
	long long int	max = std::max(num[0], (std::max(num[1], num[2])));
	for (; i < 3; i++)
	{
		if (max == num[i])
			break ;
	}
	if (max != num[2])
	{
		num[i] = num[2];
		num[2] = max;
	}
}

int	main(void)
{
	long long int	num[3];

	while (true)
	{
		std::cin >> num[0] >> num[1] >> num[2];
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break ;
		maxToz(num);
		if (std::pow(num[0], 2) + std::pow(num[1], 2) == std::pow(num[2], 2))
			std::cout << "right\n";
		else
			std::cout << "wrong\n";
	}
	return (0);
}