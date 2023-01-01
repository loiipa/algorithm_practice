#include <iostream>
#include <vector>

int main()
{
    int rowNum, columnNum;
    std::cin >> rowNum >> columnNum;

    std::vector<std::vector<int>> matrix{};
    matrix.resize(rowNum);
    int num = 0;

    // matrix A
    for (auto rowIdx = 0; rowIdx < rowNum; ++rowIdx)
    {
        std::vector<int> rowData{};
        rowData.resize(columnNum);

        for (auto columnIdx = 0; columnIdx < columnNum; ++columnIdx)
        {
            std::cin >> num;
            rowData.at(columnIdx) = num;
        }
        matrix.at(rowIdx) = std::move(rowData);
    }

    // matrix A+B
    for (auto rowIdx = 0; rowIdx < rowNum; ++rowIdx)
    {
        for (auto columnIdx = 0; columnIdx < columnNum; ++columnIdx)
        {
            std::cin >> num;
            matrix[rowIdx][columnIdx] += num;
        }
    }

    // matrix output
    for (auto rowIdx = 0; rowIdx < rowNum; ++rowIdx)
    {
        for (auto columnIdx = 0; columnIdx < columnNum; ++columnIdx)
            std::cout << matrix[rowIdx][columnIdx] << ' ';
        std::cout << '\n';
    }
}
