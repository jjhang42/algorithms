#include <iostream>
#include <vector>
#include <algorithm>

int	getMin(int i, int l)
{
	int res = (i - l + 1);
	if (res < 0)
		return (0);
	return (res);
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	n;
	int	l;

	std::cin >> n;
	std::cin >> l;
	std::vector<int>	v;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		int	min = getMin(i, l);
	}
	return (0);
}
