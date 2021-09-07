#include <iostream>
using namespace std;

long long arr[1000002],  prime_check[1000001];

void	erase_nono_number(long long min, long long max, long long prime)
{
	long long	i;

	i = min / prime;
	if (min % prime != 0)
		i++;
	while (prime * i <= max)
	{
		//제곱ㄴㄴ수면 0, ㄴㄴ수 아니면 1
		arr[prime * i - min] = 1;
		i++;
	}
}

int	main(void){
	long long	i, prime;
	long long	min, max, answer;

	cin >> min >> max;

	// min~max 영역 초기화
	for (i = 0; i < max - min + 1; i++)
		arr[i] = 0;
	arr[i] = -1;

	// 에라토스테네스의 체 초기화
	for (i = 0; i < 1000001; i++)
		prime_check[i] = 0;

	// 에라토스테네스의 체 생성
	prime_check[1] = 1;
	prime = 2;
	while (prime <= 1000000)
	{
		//소수면 0 아니면 1
		if (prime_check[prime] == 0){
			i = prime;
			while (prime * i <= 1000000)
			{
				prime_check[prime * i] = 1;
				i++;
			}
		}
		prime++;
	}

	// 제곱ㄴㄴ수 체크
	prime = 2;
	while (prime * prime <= max)
	{
		if (prime_check[prime] == 0)
			erase_nono_number(min, max, prime * prime);
		prime++;
	}

	i = 0;
	answer = 0;
	while (arr[i] != -1)
	{
		if (arr[i] == 0){
			answer++;
		}
		i++;
	}
	cout << answer;
	return (0);
}
