#include <iostream>
#include <algorithm>
#include <vector>

namespace
{
    using Itr = std::vector<int>::iterator;
}

Itr QuickSortLogic(Itr begin, Itr end)
{
    auto pivot = end;
    auto pivotValue = *begin;

    --end;
    for (; begin != end; --end)
    {
        if (*end > pivotValue)
        {
            --pivot;
            if (end != pivot)
                std::swap(*end, *pivot);
        }
    }

    --pivot;
    if (begin != pivot)
        std::swap(*begin, *pivot);

    return pivot;
}

void Sort3(Itr itr1, Itr itr2, Itr itr3)
{
    // 123 132 231
    if (*itr1 <= *itr2)
    {
        // 132 -> 123 / 231 -> 213
        if (*itr2 > *itr3)
            std::swap(*itr2, *itr3);
        
        // 213 ->  123
        if (*itr1 > *itr2)
            std::swap(*itr1, *itr2);
    }
    // 321 312 213
    else
    {
        // 321 -> 123 / 312 -> 213
        if (*itr1 > *itr3)
            std::swap(*itr1, *itr3);

        // 213 -> 123
        if (*itr1 > *itr2)
            std::swap(*itr1, *itr2);
    }
}

void Sort4(Itr itr1, Itr itr2, Itr itr3, Itr itr4)
{
    Sort3(itr1, itr2, itr3);

    if (*itr3 > *itr4)
    {
        std::swap(*itr3, *itr4);
        if (*itr2 > *itr3)
        {
            std::swap(*itr2, *itr3);
            if (*itr1 > *itr2)
                std::swap(*itr1, *itr2);
        }
    }
}

void QuickSort(Itr begin, Itr end)
{
    switch(end - begin)
    {
    case 0:
    case 1:
        return;
    case 2:
        if (*begin > *(end - 1))
            std::swap(*begin, *(end - 1));
        return;
    case 3:
        Sort3(begin, begin + 1, begin + 2);
        return;
    case 4:
        Sort4(begin, begin + 1, begin + 2, begin + 3);
        return;
    }

    auto nextPivot = QuickSortLogic(begin, end);

    QuickSort(begin, nextPivot);
    QuickSort(nextPivot + 1, end);
}

int main()
{
    int totalNum = 0, num = 0;
    std::vector<int> vecNum;

    // 입력부
    std::cin >> totalNum;
    vecNum.reserve(totalNum);
    for (auto idx = 0; idx < totalNum; ++idx)
    {
        std::cin >> num;
        vecNum.emplace_back(num);
    }

    // std 라이브러리 이용한 정렬
    // std::sort(vecNum.begin(), vecNum.end());

    // quick sort
    QuickSort(vecNum.begin(), vecNum.end());

    // 출력부
    for (auto sortNum : vecNum)
    {
        std::cout << sortNum << std::endl;
    }
}
