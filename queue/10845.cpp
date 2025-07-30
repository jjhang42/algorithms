#include <iostream>
#include <queue>
#include <string>

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::queue<int>	q;
	int	n;
	int	num;

	std::cin >> n;
	for (int i = 0; i < n;i++)
	{
		std::string	cmd;
		std::cin >> cmd;
		if (cmd == "push")
		{
			std::cin >> num;
			q.push(num);
		}
		else if (cmd == "pop")
		{
			if (q.size() != 0)
			{
				num = q.front();
				q.pop();
			}
			else
				num = -1;
			std::cout << num << '\n';
		}
		else if (cmd == "size")
			std::cout << q.size() << '\n';
		else if (cmd == "empty")
			std::cout << q.empty() << '\n';
		else if (cmd == "front")
		{
			if (q.size() != 0)
				num = q.front();
			else
				num = -1;
			std::cout << num << '\n';
		}
		else if (cmd == "back")
		{
			if (q.size() != 0)
				num = q.back();
			else
				num = -1;
			std::cout << num << '\n';
		}
	}
	return (0);
}