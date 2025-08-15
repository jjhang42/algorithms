#include <iostream>
#include <cstring>

int	main(void)
{
	int	n;
	int	primeArr[1001];
	std::cin >> n;

	std::memset(primeArr, -1,sizeof(int) * 1000);
	for (int i = 0; i < 1001; i++)
	{
		if (i < 2)
		{
			primeArr[i] = 0;
			continue;
		}
		else if (primeArr[i] == 0)
			continue;
		for (int j = 1; j * i < 1001; j++)
		{
			if (j * i == i)
				primeArr[j * i] = 1;
			else
				primeArr[j * i] = 0;
		}
	}
	int	res = 0;
	for (int i = 0; i < n; i++)
	{
		int	num;
		std::cin >> num;
		if (primeArr[num] > 0)
			res++;
	}
	std::cout << res << '\n';
	return (0);
}