#include <iostream>
#include <queue>

int	solutions(int start, int end, std::queue<int> q, int board[100001])
{
	int	time = 0;
	int	dx[2] = {-1, 1};
	q.push(start);
	while (true)
	{
		int size = q.size();
		while (size--)
		{
			int	cur = q.front();
			q.pop();
			while (cur < 100001)
			{
				if (cur < 0 || 100001 <= cur)
					break;
				if (cur == end)
					return (time);
				board[cur] = 1;
				q.push(cur);
				cur *= 2;
			}
		}
		time++;
		size = q.size();
		while (size--)
		{
			int	cur = q.front();
			q.pop();
			for (int i = 0; i < 2; i++)
			{
				int	nx = dx[i] + cur;
				if (nx < 0 || 100001 <= nx)
					continue;
				if (board[nx] != 0)
					continue;
				if (nx == cur)
					return (time);
				board[nx] = 1;
				q.push(nx);
			}
		}
	}
	return(time);
}

int	main(void)
{
	int	board[100001] = {0};
	int	start;
	int end;
	std::cin >> start >> end;
	std::queue<int>	q;
	std::cout << solutions(start, end, q, board) << '\n';
	return (0);
}