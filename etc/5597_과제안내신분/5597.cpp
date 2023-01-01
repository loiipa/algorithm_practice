#include <iostream>
#include <array>

namespace
{
    constexpr int NUMBER = 30;
}

int main()
{
    std::array<bool, NUMBER + 1> studentNum{};
    int num;
    for (auto i = 0; i < NUMBER - 2; ++i)
    {
        std::cin >> num;
        studentNum.at(num) = true;
    }

    for (auto i = 1; i <= NUMBER; ++i)
    {
        if (studentNum.at(i) == false)
            std::cout << i << '\n';
    }
}
