#include <iostream>

int	main(void)
{
	int	x, y;
	std::cin >> x >> y;
	int	n[1002] = {0};
	int	start = 1;
	int	max = 2;
	int	num = 1;
	while (start < 1001)
	{
		for (int i = start; i < max && i < 1001; i++)
		{
			n[i] = num;
		}
		num++;
		start = max;
		max = max + num;
	}
	
	int	res = 0;
	for (int i = x; i <= y; i++)
		res += n[i];
	std::cout << res << '\n';
	return (0);
}