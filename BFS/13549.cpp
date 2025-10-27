#include <iostream>
#include <queue>
#include <deque>

int	solutions(int start, int end, std::deque<std::pair<int, int>> q, int board[100001])
{
	int	dx[2] = {-1, 1};
	q.push_back({start, 0});
	board[start] = 1;
	while (!q.empty())
	{
		std::pair<int, int>	cur = q.front();
		q.pop_front();
		{
			int	times = cur.first * 2;
			if (0 <= times && times <= 100001 && board[times] == 0)
			{
				if (times == end)
					return (cur.second);
				board[times] = 1;
				q.push_front({times, cur.second});
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int	nx = dx[i] + cur.first;
			int	time = cur.second + 1;
			if (nx < 0 || 100001 <= nx)
				continue;
			if (board[nx] != 0)
				continue;
			if (nx == end)
				return (time);
			board[nx] = 1;
			q.push_back({nx, time});
		}
	}
	return(0);
}

int	main(void)
{
	int	board[100001] = {0};
	int	start;
	int end;
	std::cin >> start >> end;
	std::deque<std::pair<int, int>>	q;
	std::cout << solutions(start, end, q, board) << '\n';
	return (0);
}