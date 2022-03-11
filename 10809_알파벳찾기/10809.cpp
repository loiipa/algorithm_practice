#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	string	s;
	vector<int>	v(27, -1);
	int idx;

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		idx = s[i] % 32;
		if (v[idx] == -1)
			v[idx] = i;
	}
	for (int i = 1; i < 27; i++)
	{
		cout << v[i];
		if (i < 26)
			cout << " ";
	}
	return 0;
}
