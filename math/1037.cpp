#include <iostream>
#include <stack>

int	main(void)
{
	int	n;
	std::cin >> n;
	int	min = 1000000;
	int	max = 1;
	for (int i = 0; i < n; i++)
	{
		int	input;
		std::cin >> input;
		if (min > input)
			min = input;
		if (max < input)
			max = input;
	}
	std::cout << min * max;
	return (0);
}