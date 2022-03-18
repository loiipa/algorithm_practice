#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int	main(void)
{
	string		num;
	int			sum = 0;

	cin >> num;
	sort(num.begin(), num.end(), greater<char>());

	for (int i = 0; i < num.length(); i++)
		sum += num[i] - '0';

	if (num[num.length() - 1] != '0' || sum % 3 != 0)
		cout << -1;
	else
		cout << num;
	return 0;
}
