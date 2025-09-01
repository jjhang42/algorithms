#include <iostream>
#include <string>

int	main(void)
{
	char	c[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	while (true)
	{
		int	cnt = 0;
		std::string	input;
		std::getline(std::cin, input);
		if (input == "#")
			break ;
		for (int i = 0; input[i] != '\0'; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (input[i] == c[j])
					cnt++;
			}
		}
		std::cout << cnt << '\n';
	}
	return (0);
}