#include <iostream>
#include <queue>

int	solution(int n, int board[100001], int inDegree[100001])
{
	std::queue<int>	q;
	int	res = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
			res++;
		}
	}
	while (!q.empty())
	{
		int	cur = q.front();
		q.pop();
		if (cur < 1 || n + 1 < cur)
			continue;
		inDegree[board[cur]]--;
		if (inDegree[board[cur]] == 0)
		{
			res++;
			q.push(board[cur]);
		}
	}
	return (res);
}

void	initArg(int *n, int board[100001], int inDegree[100001])
{
	std::cin >> *n;
	for (int i = 1; i < (*n + 1); i++)
	{
		int	tem;
		std::cin >> tem;
		board[i] = tem;
		inDegree[tem]++;
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
		int	board[100001] = {0};
		int	inDegree[100001] = {0};
		int	n;
		initArg(&n, board, inDegree);
		std::cout << solution(n, board, inDegree) << '\n';
	}
	return (0);
}