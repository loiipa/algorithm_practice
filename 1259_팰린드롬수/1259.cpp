#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string	s;
	int		size;
	string	answer;

	cin >> s;
	size = s.size();

	while (size != 1 || s[0] != '0')
	{
		for (int i = 0; i < s.size()/2 + 1; i++)
		{
			if (s[i] != s[size-1-i])
			{
				answer += "no\n";
				break ;
			}
			if (i == s.size()/2)
				answer += "yes\n";
		}
		cin >> s;
		size = s.size();
	}
	cout << answer;
}
