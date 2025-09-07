#include <iostream>
#include <algorithm>

int	GCD(int x, int y)
{
	int	res = std::min(x, y);
	for (; 0 < res; --res)
	{
		if (x % res == 0 && y % res == 0)
			break ;
	}
	return (res);
}

int	LCM(int gcd, int x, int y)
{
	return (x * y / gcd);
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int	x, y;
	std::cin >> x >> y;

	int	gcd = GCD(x, y);
	int	lcm = LCM(gcd, x, y);
	std::cout << gcd << "\n" << lcm << '\n';
	return (0);
}