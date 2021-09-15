#include <iostream>
#include <vector>

using namespace std;

int				n, m;
vector	<int>	v, answer;

void	DFS(int index, int start)
{
	if (index == m)
	{
		for(int i = 0; i < m - 1; i++)
			cout << answer.at(i) << ' ';
		cout << answer.at(m - 1) << '\n';
	}
	else
	{
		for(int i = start; i < n; i++)
			if (v.at(i))
			{
				answer.push_back(v.at(i));
				DFS(index + 1, i);
				answer.pop_back();
			}
	}
}

int		main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		v.push_back(i);
	DFS(0, 0);
}
