#include <iostream>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	long long int	n;
	long long int	arr[6];
	long long int	shirts;
	long long int	pen;

	long long int	TAnswer = 0;

	std::cin >> n;
	for(int i = 0; i < 6; i++)
		std::cin >> arr[i];
	std::cin >> shirts >> pen;


	for (int i = 0; i < 6; i++)
		TAnswer += arr[i] / shirts + (arr[i] % shirts != 0);
	std::cout << TAnswer << '\n';
	std::cout << n / pen << ' ' << n % pen << '\n';
	return (0);
}