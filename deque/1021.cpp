#include <iostream>
#include <deque>
#include <algorithm>

std::deque<int>	initDeque( int n )
{
	std::deque<int>	res;
	for (int i = 0; i < n; i++)
	{
		res.push_back(i + 1);
	}
	return (res);
}

void	rotateLeft(std::deque<int> &d)
{
	std::rotate(d.begin(), d.begin() + 1, d.end());
}

void	rotateRight(std::deque<int> &d)
{
	std::rotate(d.rbegin(), d.rbegin() + 1, d.rend());
}

int	getDistance(int dst, std::deque<int> &d)
{
	int	left = 0;
	int	right = 0;
	for (std::deque<int>::iterator it = d.begin(); it != d.end() && *it != dst; ++it)
		left++;
	for (std::deque<int>::reverse_iterator it = d.rbegin(); it != d.rend() && *it != dst; ++it)
		right++;
	if (left <= right)
		return (0);
	return (1);
}

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	cnt = 0;
	int	n;
	int	m;

	std::cin >> n;
	std::cin >> m;
	std::deque<int>	d = initDeque(n);

	for (int i = 0; i < m; i++)
	{
		int num;

		std::cin >> num;
		if (num == d.front())
			d.pop_front();
		else
		{
			int cycle = getDistance(num, d);
			while (true)
			{
				if (num == d.front())
					break;
				if (cycle == 0)
					rotateLeft(d);
				else
					rotateRight(d);
				cnt++;
			}
			d.pop_front();
		}
	}
	std::cout << cnt << "\n";
	return(0);
}