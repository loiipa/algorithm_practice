#include <iostream>
#include <vector>
#include <queue>

std::queue<std::vector<int>> GetPermutationIndex(const int idxMax)
{
    std::queue<std::vector<int>> qPermutation{};
    std::vector<int> vecElem = {0};

    if (idxMax < 1)
        return {};

    qPermutation.emplace(vecElem);

    for (int idx = 1; idx < idxMax; ++idx)
    {
        while (qPermutation.front().size() < idx + 1)
        {
            vecElem = std::move(qPermutation.front());
            qPermutation.pop();

            for (int idxElem = 0; idxElem <= vecElem.size(); ++idxElem)
            {
                auto vecElemTmp = vecElem;
                vecElemTmp.insert(vecElemTmp.begin() + idxElem, idx);
                qPermutation.emplace(vecElemTmp);
            }
        }
    }

    return qPermutation;
}

int main()
{
    int idxMax = 0;

    std::cout << "enter number : ";
    std::cin >> idxMax;

    auto qPermutation = GetPermutationIndex(idxMax);
    
    for (; !qPermutation.empty(); qPermutation.pop())
    {
        std::cout << qPermutation.front().size() << " [ ";
        for (const auto& value : qPermutation.front())
        {
            std::cout << value;
            std::cout << " ";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
}
