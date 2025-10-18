#include <iostream>

int	main(void)
{
	int	fac[13] = {0};
	fac[0] = 1;
	for (int i = 1; i < 13; i++)
	{
		fac[i] = fac[i - 1] * i;
	}
	int	n;
	std::cin >> n;
	
	std::cout << fac[n] << '\n';
	return (0);
}