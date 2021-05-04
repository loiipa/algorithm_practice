#include <iostream>

using namespace std;

	int		g_n;
	int		g_m;
	int		g_map[510][510];
	int		g_answer = -1;
	int		g_move[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; 

void	dfs(int deep, int n_cur, int m_cur, int answer_tmp)
{
	int		n_next;
	int		m_next;
	int		tmp;

	if (deep == 0)
	{
		tmp = g_map[n_cur][m_cur];
		
		g_map[n_cur][m_cur] = 0;
		answer_tmp += tmp;
		dfs(1, n_cur, m_cur, answer_tmp);
		g_map[n_cur][m_cur] = tmp;
	}
	else if (deep < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			n_next = n_cur + g_move[i][1];
			m_next = m_cur + g_move[i][0];
			if (n_next >= 0 && m_next >= 0 && n_next < g_n && m_next < g_m)
			{
				tmp = g_map[n_next][m_next];

				answer_tmp += tmp;
				g_map[n_next][m_next] = 0;
				dfs(deep + 1, n_next, m_next, answer_tmp);
				g_map[n_next][m_next] = tmp;
				answer_tmp -= g_map[n_next][m_next];
			}
		}
	}
	else
		if (answer_tmp > g_answer)
			g_answer = answer_tmp;
}

void	shape_T(int deep, int n_cur, int m_cur, int answer_tmp, int num)
{
	int		n_next;
	int		m_next;

	if (deep == 0)
	{
		answer_tmp += g_map[n_cur][m_cur];
		shape_T(1, n_cur, m_cur, answer_tmp, 0);
	}
	else if (deep < 4)
	{
		for (int i = num; i < 4; i++)
		{
			n_next = n_cur + g_move[i][1];
			m_next = m_cur + g_move[i][0];
			if (n_next >= 0 && m_next >= 0 && n_next < g_n && m_next < g_m)
			{
				answer_tmp += g_map[n_next][m_next];
				shape_T(deep + 1, n_cur, m_cur, answer_tmp, i + 1);
				answer_tmp -= g_map[n_next][m_next];
			}
		}
	}
	else
		if (answer_tmp > g_answer)
			g_answer = answer_tmp;
}

int		main(void)
{

	cin >> g_n >> g_m;

	for (int i = 0; i < g_n; i++)
		 for (int j = 0; j < g_m; j++)
		 	cin >> g_map[i][j];

	for (int i = 0; i < g_n; i++)
	{
		 for (int j = 0; j < g_m; j++)
		 {
			dfs(0, i, j, 0);
			shape_T(0, i, j, 0, 0);
		 }
	}
	cout << g_answer;
}
