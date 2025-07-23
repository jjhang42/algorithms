#include <iostream>
#include <string>
#include <cstring>

int	whatsalpha( char c )
{
	return (c - 'a');
}

int	main( void )
{
	std::string	s;
	std::cin >> s;
	int	c[27];
	int	arrnum;

	std::memset(c, 0, sizeof(int) * 27);
	for (int i = 0; s[i] != '\0'; i++)
	{
		arrnum = whatsalpha(s[i]);
		c[arrnum]++;		
	}
	for (int i = 0; i < 26; i++)
	{
		std::cout << c[i] << " ";
	}
	return (0);
}