#include <iostream>
#include <deque>
#include <string>

void	printArr(std::deque<int> &d, int flag)
{
	std::cout << "[";
	if (flag == true)
	{
		for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		{
			std::cout << *it;
			if (it + 1 != d.end())
				std::cout << ",";
		}
	}
	else
	{
		for (std::deque<int>::reverse_iterator it = d.rbegin(); it != d.rend(); ++it)
		{
			std::cout << *it;
			if (it + 1 != d.rend())
				std::cout << ",";
		}
	}
	std::cout << "]\n";
}

void	error(void)
{
	std::cout << "error\n";
}

std::deque<int> initDeque(char *str)
{
	std::deque<int>	d;

	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
		{
			d.push_back(strtol(str, &str, 10));
		}
		str++;
	}
	return (d);
}

void	exeCmd(std::string cmd, std::deque<int> &d, int &sign)
{
	for (int i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == 'R')
		{
			sign = !sign;
		}
		else if (cmd[i] == 'D')
		{
			if (d.size() == 0)
			{
				sign = -1;
				return ;
			}
			if (sign == true)
				d.pop_front();
			else
				d.pop_back();
		}
	}
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	t;
	
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int	flag = true;
		std::string	cmd;
		std::cin >> cmd;
		int			n;
		std::cin >> n;
		std::string	arr;
		std::cin >> arr;
		std::deque<int>	d = initDeque(const_cast<char *>(arr.c_str()));
		exeCmd(cmd, d, flag);
		if (flag != -1)
			printArr(d, flag);
		else
			error();
	}
	return (0);
}