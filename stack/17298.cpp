#include <iostream>
#include <vector>
#include <stack>

int	main(void)
{
	std::stack<std::pair<int, int> >		s;
	int										n;

	std::cin >> n;
	std::vector<int>						out(n, -1);
	for (int i = 0; i < n; i++)
	{
		std::pair<int, int>	tem;
		std::cin >> tem.first;
		tem.second = i;
		if (s.size() != 0 && tem.first > s.top().first)
		{
			while (s.size() != 0 && tem.first > s.top().first)
			{
				out[s.top().second] = tem.first;
				s.pop();
			}
		}
		s.push(tem);
	}
	for (std::vector<int>::iterator	it = out.begin(); it != out.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != out.end())
			std::cout << " ";
		else
			std::cout << "\n";
	}
	return (0);
}