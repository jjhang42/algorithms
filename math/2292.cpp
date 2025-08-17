#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    if (!(std::cin >> N)) return 0;

    if (N == 1) {
        std::cout << 1 << '\n';
        return 0;
    }

    long long max_in_ring = 1;
    long long k = 0;

    while (max_in_ring < N) {
        ++k;
        max_in_ring += 6 * k;
    }
    std::cout << (k + 1) << '\n';
    return 0;
}