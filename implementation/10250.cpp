#include <iostream>

int main(void)
{
    int t;

    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int h, w, n;
        std::cin >> h >> w >> n;
        int room = ((n + h - 1) / h);
        int floor = ((n - 1) % h + 1) * 100;

        std::cout << floor + room << '\n';
    }
    return (0);
}