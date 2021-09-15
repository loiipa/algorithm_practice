#include <iostream>

using namespace std;

int			g_map[10][10];
int			g_paper[6];
int			g_answer = 26;

void		map_dfs(int x, int y, int num);

void		cover_paper(int x, int y, int num, int size)
{
	if (g_paper[size] == 0)
		return ;
	if (x + size > 10 || y + size > 10)
		return ;
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (g_map[i][j] == 0)
				return ;
	
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			g_map[i][j] = 0;

	g_paper[size]--;
	map_dfs(x, y, num + 1);
	g_paper[size]++;

	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			g_map[i][j] = 1;
	return ;
}

void		map_dfs(int x, int y, int num)
{
	if (num >= g_answer)
		return ;
	for (int i = x; i < 10; i++)
	{
		for (int j = y; j < 10; j++)
		{
			if (g_map[i][j] == 1)
			{
				for (int size = 5; size > 0; size--)
					cover_paper(i, j, num, size);
				return ;
			}
		}
		y = 0;
	}
	g_answer = num;
	return ;
}

void		init_paper(void)
{
	for (int i = 1; i < 6; i++)
		g_paper[i] = 5;
	return ;
}

int			main(void)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> g_map[i][j];
	init_paper();
	map_dfs(0, 0, 0);
	if (g_answer == 26)
		g_answer = -1;
	cout << g_answer;
}
