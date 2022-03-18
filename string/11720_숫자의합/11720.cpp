#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int		n;
	string	s;
	cin >> n >> s;

	n = 0;
	for (char c : s)
		n += c - '0';
	cout << n;
	return 0;
}
