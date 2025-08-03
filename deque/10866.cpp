#include <iostream>
#include <deque>
#include <string>

int main(void)
{
    int n;
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    std::cin >> n;
    std::deque<int>  d;
    for (int i = 0; i < n; i++)
    {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "push_front")
        {
            int tem;
            std::cin >> tem;

            d.push_front(tem);
        }
        else if (cmd == "push_back")
        {
            int tem;
            std::cin >> tem;

            d.push_back(tem);
        }
        else if (cmd == "pop_front")
        {
            if (d.size() == 0)
                std::cout << "-1\n";
            else
            {
                std::cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (d.size() == 0)
                std::cout << "-1\n";
            else
            {
                std::cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if (cmd == "size")
        {
            std::cout << d.size() << "\n";
        }
        else if (cmd == "empty")
        {
            std::cout << d.empty() << "\n";
        }
        else if (cmd == "front")
        {
            if (d.size() == 0)
                std::cout << "-1\n";
            else
                std:: cout << d.front() << "\n";
        }
        else if (cmd == "back")
        {
            if (d.size() == 0)
                std::cout << "-1\n";
            else
                std:: cout << d.back() << "\n";
        }
    }
    return (0);
}