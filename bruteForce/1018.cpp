#include <iostream>

#define W 0
#define B 1

void	printBoard(int N, int M, int board[][50])
{
	std::cout << "board" << std::endl;
	std::cout << "N: " << N << " M: " << M << std::endl;
	for (int idx1 = 0; idx1 < 8; idx1++)
	{
		for (int idx2 = 0; idx2 < 8; idx2++)
		{
			std::cout << board[N + idx1][M + idx2];
		}
		std::cout << std::endl;
	}
}

int	checkColor(int N, int M, int board[][50])
{
	int	point = board[N][M];
	int	check = 0;
	for (int idx1 = 0; idx1 < 8; idx1++)
	{
		for (int idx2 = 0; idx2 < 8; idx2++)
		{
			if (point != board[N + idx1][M + idx2])
				check++;
			if (idx2 != 7)
				point = !point;
		}
	}
	return (check);
}

int	check(int N, int M, int board[][50])
{
	int	curMix;
	curMix = 64;
	for (int idx1 = 0; idx1 + 7 < N; idx1++)
	{
		for (int idx2 = 0; idx2 + 7 < M; idx2++)
		{
			int	tem = checkColor(idx1, idx2, board);
			tem = std::min(tem, 64 - tem);
			if (tem < curMix)
				curMix = tem;
		}
	}
	return (curMix);
}

//어디를 자를지 생각->
//색칠할 색 선택
//갯수파악
//출력
int	main(void)
{
	int	N, M;
	int	board[50][50];
	int	res;
	std::cin >> N >> M;
	
	//init
	for (int idx1 = 0; idx1 < 50; idx1++)
	{
		for (int idx2 = 0; idx2 < 50; idx2++)
		{
			board[idx1][idx2] = -1;
		}
	}

	for (int idx1 = 0; idx1 < N; idx1++)
	{
		for (int idx2 = 0; idx2 < M; idx2++)
		{
			char tem;
			std::cin >> tem;
			if (tem == 'W')
				board[idx1][idx2] = W;
			else
				board[idx1][idx2] = B;
		}
	}
	// std::cout << "<board>" << std::endl;
	// for (int idx1 = 0; idx1 < N; idx1++)
	// {
	// 	for (int idx2 = 0; idx2 < M; idx2++)
	// 	{
	// 		std::cout << board[idx1][idx2];
	// 	}
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl;
	std::cout << check(N, M, board);
	return (0);
}