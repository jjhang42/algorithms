#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int	n, k, x;
	std::cin >> n >> k;
	std::vector<int>	v;
	for (int i = 0; i < n; i++)
	{
		int	tem;
		std::cin >> tem;
		v.push_back(tem);
	}
	std::sort(v.rbegin(), v.rend());
	std::cout << v[k - 1];
	return (0);
}