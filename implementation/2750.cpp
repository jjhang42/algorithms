#include <iostream>
#include <algorithm>
#include <vector>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n;
	std::vector<int>	v;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int	num;
		std::cin >> num;
		v.push_back(num);
	}
	std::sort(v.begin(), v.end());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << '\n';
	}
	return (0);
}