#include <iostream>
#include <functional>

int main()
{
    int num ;
    std::cin >> num;

    std::function<int(int)> Factorial = [&Factorial](int num) -> int
    {
        return num > 1 ? num * Factorial(num - 1) : 1;
    };

    std::cout << Factorial(num);
}
