#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int				n, k, a;
	vector <int>	v;
	int				answer = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	while (k && n > 0)
	{
		if (k < v.back())
		{
			v.pop_back();
			n--;
		}
		else
		{
			while (k >= v.back())
			{
				k -= v.back();
				answer++;
			}
			v.pop_back();
		}
	}
	cout << answer;
	return (0);
}
