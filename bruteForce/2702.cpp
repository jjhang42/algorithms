#include <iostream>

int get_gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;

	while (n--) {
		int a, b;
		std::cin >> a >> b;
		int gcd = get_gcd(a, b);
		int lcm = a * b / gcd;
		std::cout << lcm << " " << gcd << '\n';
	}
	return 0;
}