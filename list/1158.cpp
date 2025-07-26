#include <iostream>
#include <list>

int	main(void)
{
	std::list<int>	lst;
	int				n;
	int				k;

	std::cin >> n;
	for (int i = 0; i < n; i++)
		lst.push_back(i + 1);
	std::cin >> k;
	std::list<int>::iterator	it = lst.begin();
	std::cout << "<";
	for ( ; lst.size() != 0; )
	{
		for (int j = 1; j < k; j++)
		{
			if (it != lst.end())
				it++;
			if (it == lst.end())
				it = lst.begin();
		}
		std::list<int>::iterator	tem = it;
		tem++;
		if (tem == lst.end())
			tem = lst.begin();
		std::cout << *it;
		if (lst.size() != 1)
			std::cout << ", ";
		lst.erase(it);
		it = tem;
	}
	std::cout << ">";
	return (0);
}