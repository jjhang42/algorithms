#include <iostream>
#include <string>

int	main(void)
{
	int	n;
	std::cin >> n;
	for (int j = 0; j < n; j++)
	{
		std::string			str;

		std::cin >> str;
		int	cnt = 0;
		int	res = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == 'O')
			{
				cnt++;
				res += cnt;
			}
			if (str[i] == 'X')
				cnt = 0;
		}
		std::cout << res << '\n';
	}
	return (0);
}