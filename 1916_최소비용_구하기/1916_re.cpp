#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

struct			t_ticket
{
	int			start;
	int			end;
	int			fee;
};

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second < b.second);
}

int				main(void)
{
	int			n;
	int			m;
	t_ticket	t;
	int			fee_table[1001][1001];
	long long	fee_min[1001];
	//int			visit_city[1001];
	//int			visit_num = 0;
	//long long	tmp = LLONG_MAX;
	int			st;
	std::vector <std::pair<int, long long> >	vec;
	std::pair<int, long long> fee_info;

	//a->b로 가는 요금을 -1로 초기화
	//이차원 벡터는 너무 복잡해지는 것 같아서 배열로 정보를 담으려고 함.
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
			fee_table[i][j] = -1;

	//a->b 정보 파싱
	std::cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> t.start >> t.end >> t.fee;
		fee_table[t.start][t.end] = t.fee;
	}

	//출발지와 목적지 파싱
	std::cin >> t.start >> t.end;
	t.fee = 0;

	//최저요금을 구해야하기에 적당히 큰 수로 초기화 + visit_city 초기화
	for (int i = 1; i <= n; i++)
	{
		fee_min[i] = LLONG_MAX;
		//visit_city[i] = 0;
	}
	fee_min[t.start] = 0;

	vec.push_back(std::pair<int, long long>(t.start, 0));
	while (!vec.empty())
	{
		fee_info = vec.front();

		st = fee_info.first;
		for (int dst = 1; dst <= n; dst++)
		{
			if (fee_table[st][dst] >= 0 && fee_min[st] + fee_table[st][dst] < fee_min[dst])
			{
				fee_min[dst] = fee_min[st] + fee_table[st][dst];
				//std::cout << fee_min[dst] << std::endl;
				vec.push_back(std::pair<int, long long>(dst, fee_min[dst]));
			}

		}
		vec.erase(vec.begin());
		sort(vec.begin(), vec.end(), compare);
	}
	std::cout << fee_min[t.end];
}
