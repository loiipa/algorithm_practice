#include <iostream>

int main()
{
    std::pair<int, int> num;
    std::cin >> num.first >> num.second;

    auto NewOperator = [](const int& num1, const int& num2)
    {
        return static_cast<long long>(num1 + num2) * static_cast<long long>(num1 - num2);
    };

    std::cout << NewOperator(num.first, num.second) << std::endl;
}
