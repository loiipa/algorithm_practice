#include <cstdio>
#include <array>
#include <memory>

namespace
{
	constexpr int NUMBER = 1000000;
}

class PrimeNumber
{
public:
	PrimeNumber() { SetPrime(NUMBER); }
	PrimeNumber(PrimeNumber& primeNumber) = delete;
	void operator=(const PrimeNumber&) = delete;

	static std::shared_ptr<PrimeNumber> GetInstance();
	const std::array<bool, NUMBER + 1>& GetPrimeArray() const { return primeArray; }

	int GetGoldbachNumber(const int& num) const;

protected:
	void SetPrime(const int& num);

	static std::shared_ptr<PrimeNumber> primeNumber;
	std::array<bool, NUMBER + 1> primeArray{};
};

std::shared_ptr<PrimeNumber> PrimeNumber::GetInstance()
{
	if (primeNumber == nullptr)
		primeNumber = std::make_shared<PrimeNumber>();
	return primeNumber;
}

void PrimeNumber::SetPrime(const int& num)
{
	for (int prime = 2; prime * prime < num; prime++)
	{
		if (!primeArray[prime])
		{
			for (int i = prime; i <= num / prime; i++)
				primeArray[prime * i] = true;
		}
	}
}

int PrimeNumber::GetGoldbachNumber(const int& num) const
{
	int numFirst = 0;
	for (auto i = 3; i <= num / 2; i += 2)
	{
		if (primeArray[i] == false && primeArray[num - i] == false)
			return i;
	}
	return numFirst;
}

std::shared_ptr<PrimeNumber> PrimeNumber::primeNumber = nullptr;

int main()
{
	auto primeNumber = PrimeNumber::GetInstance();
	int num = 1;

	while (num > 0)
	{
		scanf("%d", &num);
		if (num / 2 == 0 || num > NUMBER)
			continue;

		auto numFirst = primeNumber->GetGoldbachNumber(num);
		if (num > 1 && numFirst > 0)
			printf("%d = %d + %d \n", num, numFirst, num - numFirst);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
}
