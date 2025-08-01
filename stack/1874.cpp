#include <iostream>
#include <stack>
#include <vector>

int	main(void)
{
	std::vector<char>	output;
	std::stack<int>		s;
	int					n;
	int					i = 0;
	bool				flag = false;

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;

	while (i < n || s.size() != 0)
	{
		int	dst;

		std::cin >> dst;
		for (; i < dst; i++)
		{
			s.push(i + 1);
			output.push_back('+');
			flag = true;
		}
		if (s.size() != 0 && dst == s.top())
		{
			output.push_back('-');
			s.pop();
		}
		else if (s.size() == 0 && flag == true)
			break;
		else
		{
			std::cout << "NO\n";
			return (0);
		}
	}

	for (std::vector<char>::iterator it = output.begin(); it != output.end(); it++)
	{
		std::cout << *it << '\n';
	}
	return (0);
}