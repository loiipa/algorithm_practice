#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix() = delete;
    Matrix(int row, int column) { SetSizeMatrix(row, column); }
    Matrix operator+(Matrix &other);
    const auto& GetMatrix() const { return matrix; }
    const auto& GetMatrix(const int& row, const int& column) const { return matrix.at(row).at(column); }
    void SetMatrix(const int& row, const int& column, const int& value);

private:
    void SetSizeMatrix(const int& row, const int& column);
    std::vector<std::vector<int>> matrix{};
};

// todo : template<row, column>
Matrix Matrix::operator+(Matrix &other)
{
    int rowNum = this->matrix.size();
    int columnNum = this->matrix.at(0).size();
    auto newMatrix = Matrix(rowNum, columnNum);

    for (auto rowIdx = 0; rowIdx < rowNum; ++rowIdx)
    {
        for (auto columnIdx = 0; columnIdx < columnNum; ++columnIdx)
        {
            auto value = this->matrix.at(rowIdx).at(columnIdx) + other.matrix.at(rowIdx).at(columnIdx);
            newMatrix.SetMatrix(rowIdx, columnIdx, value);
        }
    }
    return newMatrix;
}

void Matrix::SetMatrix(const int& row, const int& column, const int& value)
{
    matrix.at(row).at(column) = value;
}

void Matrix::SetSizeMatrix(const int& row, const int& column)
{
    matrix.resize(row);
    for (auto& vec : matrix)
        vec.resize(column);
}

int main()
{
    int rowNum, columnNum;
    std::cin >> rowNum >> columnNum;

    auto matrixA = Matrix(rowNum, columnNum);
    auto matrixB = Matrix(rowNum, columnNum);

    auto InputForMatrix = [&rowNum, &columnNum](auto& matrix)
    {
        int num = 0;
        for (auto rowIdx = 0; rowIdx < rowNum; ++rowIdx)
        {
            for (auto columnIdx = 0; columnIdx < columnNum; ++columnIdx)
            {
                std::cin >> num;
                matrix.SetMatrix(rowIdx, columnIdx, num);
            }
        }
    };

    auto OutputForMatrix = [&rowNum, &columnNum](const auto& matrix)
    {
        for (auto rowIdx = 0; rowIdx < rowNum; ++rowIdx)
        {
            for (auto columnIdx = 0; columnIdx < columnNum; ++columnIdx)
                std::cout << matrix.GetMatrix(rowIdx, columnIdx) << ' ';
            std::cout << '\n';
        }
    };

    InputForMatrix(matrixA);
    InputForMatrix(matrixB);
    OutputForMatrix(matrixA + matrixB);
}
