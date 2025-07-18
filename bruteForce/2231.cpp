#include <iostream>

int	getSum( int num )
{
	int res = 0;
	while (num != 0)
	{
		res += (num % 10);
		num = num / 10;
	}
	return (res);
}

int	checkConstructor( int N )
{
	int	M = 0;
	int	tem;

	while ( M < N )
	{
		tem = getSum(M);
		if ( M + tem == N )
			return ( M );
		M++;
	}
	return ( 0 );
}

int	main( void )
{
	int	N; /* Input */
	int	M; /* Constructor */

	std::cin >> N;
	M = checkConstructor(N);
	std::cout << M;
	return (0);
}