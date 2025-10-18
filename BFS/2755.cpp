#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int	main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int	n;
	int	arr[27] = {0};
	int	classPoint = 0;
	float score = 0;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	input;
		std::cin >> input;
		int	tem;
		std::cin >> tem;
		classPoint += tem;
		std::cin >> input;
		if (input == "A+")
			score += tem * 4.3;
		else if (input == "A0")
			score += tem * 4.0;
		else if (input == "A-")
			score += tem * 3.7;
		else if (input == "B+")
			score += tem * 3.3;
		else if (input == "B0")
			score += tem * 3.0;
		else if (input == "B-")
			score += tem * 2.7;
		else if (input == "C+")
			score += tem * 2.3;
		else if (input == "C0")
			score += tem * 2.0;
		else if (input == "C-")
			score += tem * 1.7;
		else if (input == "D+")
			score += tem * 1.3;
		else if (input == "D0")
			score += tem * 1.0;
		else if (input == "D-")
			score += tem * 0.7;
		else if (input == "F")
			score += tem * 0.0;
	}
	float t = round(score / (float)classPoint * 100);
	printf ("%.2f\n", t / 100);
	return (0);
}