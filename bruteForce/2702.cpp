#include <iostream>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int	n;
	int	a, b;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a >> b;
		int	gcd = 0, lcm;
		for (int j = 0; j < a || j < b; j++)
		{
			if (a % j == 0 && b % j == 0 && gcd < j)
				gcd = j;
		}
		lcm = a * b / gcd;
		std::cout << lcm << " " << gcd << '\n';
	}
	return (0);
}