#include <iostream>
#include <algorithm>
#include <strings.h>
int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int	arr[10001];
	int	n;

	std::cin >> n;
	bzero(arr, sizeof(int) * 10001);
	for (int i = 0; i < n; i++)
	{
		int	num = 0;
		std::cin >> num;
		arr[num]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		while (arr[i])
		{
			std::cout << i << '\n';
			arr[i]--;
		}
	}
	return (0);
}