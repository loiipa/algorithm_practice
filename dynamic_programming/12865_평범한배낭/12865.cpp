#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int> >		wv;
vector<int>					save(100001);
int		k;
int		answer = 0;

void	check_answer(int w_tmp, int v_tmp)
{
	if (save[w_tmp] < v_tmp)
		save[w_tmp] = v_tmp;
	if (answer < v_tmp)
		answer = v_tmp;
	return ;
}

void	bsq(int index, int w_tmp, int v_tmp)
{
	int w_next = 0;
	int v_next = 0;

	for (int i = index; i < wv.size(); i++)
	{
		w_next = w_tmp + wv[i].first;
		v_next = v_tmp + wv[i].second;

		if (w_next <= k && v_next > save[w_next])
		{
			check_answer(w_next, v_next);
			bsq(i+1, w_next, v_next);
		}
	}
	return ;
}

int	main(void)
{
	int n, p1, p2;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> p1 >> p2;
		wv.push_back( pair<int, int>(p1, p2) );
	}
	bsq(0, 0, 0);
	cout << answer;
}
// 8% fail
