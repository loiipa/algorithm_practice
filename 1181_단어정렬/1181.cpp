#include <iostream>
#include <set>

using namespace std;

struct cmp
{
	bool operator() (string a, string b) const
	{
		if (a.size() == b.size())
			return a < b;
		return (a.size() < b.size());
	}
};

int main(void)
{
	int			n;
	string		s;
	set<string, cmp>	strList;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		strList.insert(s);
	}
	s = "";
	for (string s_tmp : strList)
		s += s_tmp + '\n';
	cout << s;
}
