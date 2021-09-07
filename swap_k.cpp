#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;
int		answer = 100000000;
queue<vector<int> > q;
queue<int>			q2;

int		bfs(vector<int> v, int k, int s, int deep)
{
	int		check = 0;
	int		result;
	q.push(v);
	q2.push(deep);
	while (check == 0)
	{
		v = q.front();
		for (int i = 0; i < s-1; i++)
		{
			if (abs(v[i] - v[i + 1]) > k)
			{
				check = 1;
				break;
			}
		}
		if (check == 0)
			break;
		check = 0;

		v = q.front();
		result = q2.front();
		for (int i = 0; i < s; i++)
		{
			for (int j = i+1; j < s; j++)
			{
				iter_swap(v.begin() + i, v.begin() + j);
				q.push(v);
				q2.push(result + 1);
				iter_swap(v.begin() + i, v.begin() + j);
			}
		}
		q.pop();
		q2.pop();
	}
	for ()
	return (result);
}

int		solution(vector<int> numbers, int k)
{
	int		s = numbers.size();
	vector<int> vv;
	int		answer;

	vv.assign(numbers.begin(), numbers.end());
	sort(vv.begin(), vv.end());
	for(int i = 0; i < s-1; i++)
	{
		if (abs(vv[i] - vv[i + 1]) > k)
			return -1;
	}
	answer = bfs(numbers, k, s, 0);
	return answer;
}

int		main(void)
{
	int		answer;
	vector<int> vec1 = {1, 9, 3, 7, 3};
	int			k1 = 3;
	vector<int> vec2 = {3, 7, 2, 8, 6, 4, 5, 1};
	int			k2 = 3;
	answer = solution(vec1, k1);
	cout << answer << endl;
	answer = solution(vec2, k2);
	cout << answer << endl;
}
