#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int				n, m;
vector	<int>	v, answer;

void	DFS(int index)
{
	int			tmp;
	//int			tmp_i;

	if (index == 0)
	{
		tmp = 0;
		//tmp_i = 0;
	}
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
				printf("<%d %d>", tmp, v.at(i));
				if (tmp != v.at(i))
				{
					answer.push_back(v.at(i));
					tmp = v.at(i);
					//tmp_i = i;
					//v.at(i) = 0;
					DFS(index + 1);
					//v.at(i) = tmp;
					answer.pop_back();
				}
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
