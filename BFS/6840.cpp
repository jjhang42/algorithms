#include <iostream>
#include <algorithm>
#include <vector>

int	main(void)
{
	std::vector<int>	arr;
	for (int i = 0; i < 3; i++)
	{
		int	tem;
		std::cin >> tem;
		arr.push_back(tem);
	}
	std::sort(arr.begin(), arr.end());
	std::cout << arr[1] << '\n';
	return (0);
}