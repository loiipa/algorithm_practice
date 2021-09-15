#include <iostream>
#include <algorithm>
using namespace std;
int		main(void)
{
	int		n;
	int		p[1000];
	int		answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		answer += p[i] * (n - i);
	cout << answer;
}
