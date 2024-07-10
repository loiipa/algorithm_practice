#include <iostream>
#include <queue>
#include <functional>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqTop;
    std::priority_queue<int, std::vector<int>, std::less<int>> pqBottom;

    for (int idx = 0; idx < n; ++idx)
    {
        int number;
        std::cin >> number;

        if (pqBottom.empty() || pqBottom.top() > number)
        {
            pqBottom.push(number);
        }
        else
        {
            pqTop.push(number);
        }

        if (pqBottom.size() > pqTop.size() + 1)
        {
            pqTop.push(pqBottom.top());
            pqBottom.pop();
        }
        else if (pqBottom.size() < pqTop.size())
        {
            pqBottom.push(pqTop.top());
            pqTop.pop();
        }

        std::cout << pqBottom.top() << '\n';
    }
}

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::vector<int> vecNum;
//     vecNum.reserve(100000);

//     for (int idx = 0; idx < n; ++idx)
//     {
//         int number;
//         std::cin >> number;

//         vecNum.emplace_back(number);
//         std::sort(vecNum.begin(), vecNum.end());
//         int middleIdx = idx % 2 == 0 ? idx/2 : (idx+1)/2 - 1;

//         std::cout << vecNum[middleIdx] << '\n';
//     }
// }

// int main()
// {
    // int n;
    // std::multiset<int> setNum;
    // // std::cin >> n;
    // n = 100000;
    // std::vector<int> vec{};
    // vec.reserve(100000);
    // for (int idx = -10000; idx < 10000; ++idx)
    // {
    //     vec.emplace_back(idx);
    //     vec.emplace_back(idx);
    //     vec.emplace_back(idx);
    //     vec.emplace_back(idx);
    //     vec.emplace_back(idx);
    // }
    // for (int idx = 0; idx < n; ++idx)
    // {
    //     int number;
    //     number = vec[idx];
    //     // std::cin >> number;

    //     setNum.insert(number);
    //     int middleIdx = idx % 2 == 0 ? idx/2 : (idx+1)/2 - 1;

    //     auto it = setNum.begin();
    //     for (int i = 0; i < middleIdx; ++i)
    //     {
    //         ++it;
    //     }

    //     std::cout << *it << '\n';
    // }
// }
