#include <iostream>

using namespace std;

int		g_num = 200000000;
int		g_city_num;
int		g_bus_num;
int		g_fee_table[1001][1001];
int		g_city_visited[1001];

void	dfs(int start, int dest, int fee)
{
	int		tmp;

	if (fee > g_num)
		return ;
	else if (start == dest)
	{
		if (g_num > fee)
			g_num = fee;
	}
	else
	{
		for (int i = 1; i <= g_city_num; i++)
		{
			if (g_city_visited[i] == 0 && g_fee_table[start][i] < 1000000)
			{
				tmp = g_fee_table[start][i];

				g_city_visited[i] = 1;
				fee += tmp;
				g_fee_table[start][i] = 1000000;
				dfs(i, dest, fee);
				g_fee_table[start][i] = tmp;
				fee -= tmp;
				g_city_visited[i] = 0;
			}
		}
	}
}

int		main(void)
{
	int		a;
	int		b;
	int		fee;
	int		start;
	int		dest;

	cin >> g_city_num >> g_bus_num;

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			g_fee_table[i][j] = 1000000;
	for (int i = 0 ; i <= 1000; i++)
		g_city_visited[i] = 0;

	for (int i = 0; i < g_bus_num; i++)
	{
		cin >> a >> b >> fee;
		if (g_fee_table[a][b] > fee)
			g_fee_table[a][b] = fee;
	}
	cin >> start >> dest;
	g_city_visited[start] = 1;
	dfs(start, dest, 0);
	cout << g_num;
}
