#include <iostream>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int	i = 0;
	int	num;
	int	as = 8;
	int	ds = 8;
	while (i < 8)
	{
		std::cin >> num;
		if (8 - i == num)
			ds--;
		if (i + 1 == num)
			as--;
		i++;
	}
	if (as == 0)
		std::cout << "ascending\n";
	else if (ds == 0)
		std::cout << "descending\n";
	else
		std::cout << "mixed\n";
	return (0);
}