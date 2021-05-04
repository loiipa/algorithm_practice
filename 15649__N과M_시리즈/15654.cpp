#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int				n, m;
vector	<int>	v, answer;

void	DFS(int index)
{
	int			tmp;

	if (index == m)
	{
		for(int i = 0; i < m - 1; i++)
			cout << answer.at(i) << ' ';
		cout << answer.at(m - 1) << '\n';
	}
	else
	{
		for(int i = 0; i < n; i++)
			if (v.at(i))
			{
				answer.push_back(v.at(i));
				tmp = v.at(i);
				v.at(i) = 0;
				DFS(index + 1);
				v.at(i) = tmp;
				answer.pop_back();
			}
	}
}

int		main(void)
{
	int			tmp;

	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	DFS(0);
}
