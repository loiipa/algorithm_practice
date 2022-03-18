#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
	string	s;
	int		n[2];

	for (int i = 0; i < 2; i++)
	{
		cin >> s;
		swap(s[0], s[2]);
		n[i] = stoi(s);
	}
	cout << max(n[0], n[1]);
}
