#include <iostream>
#include <string>
#include <vector>

using namespace std;

int	main(void)
{
	string		num;
	vector<int>	v(9);
	int			sum = 0;

	cin >> num;
	for (int i = 0; i < num.length(); i++)
	{
		++v[ num[i] - '0' ];
		sum += num[i] - '0';
	}
	if (sum % 3 != 0 || v[0] == 0)
		cout << -1;
	else
	{
		num.clear();
		for (int i = 9; i >= 0; i--)
		{
			while (v[i] > 0)
			{
				num.push_back(i + '0');
				--v[i];
			}
		}
		cout << num;
	}
	return 0;
}
