#include <iostream>

using namespace std;

int	main(void)
{
	int num, answer = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		answer += (num * num) % 10;
	}
	cout << answer % 10;
}
