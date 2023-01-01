#include <iostream>
#include <map>

int main()
{
    int totalNum;
    std::cin >> totalNum;

    std::map<int, int> numberOfInput;
    int num;
    for (auto i = 0; i < totalNum; ++i)
    {
        std::cin >> num;
        ++numberOfInput[num];
    }

    std::cin >> num;
    std::cout << numberOfInput[num];
}
