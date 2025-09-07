#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::vector<int>	num(5);
	for (int i = 0; i < 5; i++)
	{
		std::cin >> num[i];
	}
	int	sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += num[i];
	}
	std::cout << sum / 5 << '\n';
	std::sort(num.begin(), num.end());
	std::cout << num[2] << '\n';
 	return (0);
}