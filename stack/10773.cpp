#include <iostream>
#include <stack>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::stack<int>	s;
	int				n;
	int				sum;

	std::cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		int	input = 0;
		std::cin >> input;
		if (input == 0 && s.size() != 0)
		{
			input = s.top();
			sum -= input;
			s.pop();
		}
		else
		{
			s.push(input);
			sum += input;
		}
	}
	std::cout << sum;
	return (0);
}