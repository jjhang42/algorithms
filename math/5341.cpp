#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int>	v;
	int	tem;
	v.push_back(0);
	v.push_back(1);
	while (true)
	{
		std::cin >> tem;
		if (tem == 0)
			break ;
		if (v.size() - 1 < tem)
		{
			for (int i = v.size() - 1; i < tem; i++)
				v.push_back(v[i] + (i + 1));
		}
		std::cout << v[tem] << '\n';
	}
	return (0);
}