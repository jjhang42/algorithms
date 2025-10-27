#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <stack>

//first = val, second = pre;
void	solution(int src, int dst)
{
	if (src == dst)
	{
		std::cout << "0\n";
		std::cout << src << '\n';
		return;
	}
	int	visit[100001];
	int	board[100001] = {0};
	for (int i = 0; i < 100001; i++)
		visit[i] = INT_MAX;
	int	dx[2] = {-1, 1};
	std::queue<int>	q;
	q.push(src);
	visit[src] = 0;
	board[src] = -1;
	bool	isFind = false;
	while (!q.empty())
	{
		int	cur = q.front();
		q.pop();
		for (int i = 0; i < 2 && !isFind; i++)
		{
			int	nx = cur + dx[i];
			if (nx < 0 || 100000 < nx)
				continue;
			if (visit[nx] != INT_MAX)
				continue;
			visit[nx] = visit[cur] + 1;
			board[nx] = cur;
			if (nx == dst)
			{
				isFind = true;
				break;
			}
			q.push(nx);
		}
		if (!isFind)
		{
			int	nx = cur * 2;
			if (nx < 0 || 100000 < nx)
				continue;
			if (visit[nx] != INT_MAX)
				continue;
			visit[nx] = visit[cur] + 1;
			board[nx] = cur;
			if (nx == dst)
			{
				isFind = true;
				break;
			}
			q.push(nx);
		}
	}
	std::cout << visit[dst] << '\n';
	std::stack<int>	s;
	int	cur = dst;
	s.push(dst);
	while (board[cur] != -1)
	{
		cur = board[cur];
		s.push(cur);
	}
	while (!s.empty())
	{
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << "\n";
}

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int	src, dst;
	std::cin >> src >> dst;
	solution(src, dst);
	return (0);
}