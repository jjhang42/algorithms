#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int	n;
	int	x;
	int	res = 0;
	std::cin >> n;
	std::vector<int>	vec;
	for (int i = 0; i < n; i++)
	{
		int	tem;
		std::cin >> tem;
		vec.push_back(tem);
	}
	std::cin >> x;
	std::sort(vec.begin(), vec.end());

	for (std::vector<int>::iterator	it = vec.begin(); it != vec.end(); ++it)
	{
		int		tem = x - *it;
		bool	answer = std::binary_search(it + 1, vec.end(), tem);
		if (answer == true)
			res++;
	}
	std::cout << res;
	return(0);
}