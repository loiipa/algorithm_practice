#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	int	n, num;
	string	s;
	string	answer;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num >> s;
		for (char c : s)
		{
			for (int j = 0; j < num; j++)
				answer.push_back(c);
		}
		answer.push_back('\n');
	}
	cout << answer;
}
