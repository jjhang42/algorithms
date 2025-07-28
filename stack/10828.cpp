#include <iostream>
#include <stack>
#include <string>

int	s_top(std::stack<int> &s)
{
	int	res;

	if (s.size() == 0)
		res = -1;
	else
		res = s.top();
	return (res);
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::stack<int>	s;
	int				n;
	int				val;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	cmd;
		std::cin >> cmd;
		if (cmd == "push")
		{
			std::cin >> val;
			s.push(val);
		}
		else if (cmd == "top")
		{
			std::cout << s_top(s) << "\n";
		}
		else if (cmd == "size")
		{
			int	size = s.size();
			std::cout << size << "\n";
		}
		else if (cmd == "empty")
		{
			std::cout << s.empty() << "\n";
		}
		else if (cmd == "pop")
		{
			int	popnum = s_top(s);
			if (s.size() != 0)
				s.pop();
			std::cout << popnum << "\n";
		}
	}
	return (0);
}