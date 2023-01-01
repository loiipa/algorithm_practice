#include <iostream>
#include <ctime>

int main()
{
    // https://infocenter-archive.sybase.com/help/index.jsp?topic=/com.sybase.infocenter.dc38151.1270/html/iqref/BGBIJFAJ.htm
    setenv("TZ", "GMT", 1);
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);

    std::cout << tm.tm_year + 1900 << '-';

    std::cout.width(2);
    std::cout.fill('0');
    std::cout << tm.tm_mon + 1 << '-';

    std::cout.width(2);
    std::cout.fill('0');
    std::cout << tm.tm_mday << std::endl;
}
