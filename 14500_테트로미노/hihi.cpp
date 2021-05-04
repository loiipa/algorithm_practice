
#include <iostream>

# define MAX 501

using namespace std;

int		max_sum = -1;
int		n, m;
int		map[MAX][MAX];
bool	visited[MAX][MAX] = {{false, }, };

int		dx[4] = {1, 0, -1, 0};
int		dy[4] = {0, 1, 0, -1};

int		tx[4][4] = {{0, 0, -1 ,0}, {0, 1, -1 ,0}, {0, 1, 0 ,0}, {0, 1, 0, -1}};
int		ty[4][4] = {{0, 1, 0, -1}, {0, 0, 0, -1}, {0, 0, 1, -1}, {0, 0, 1, 0}};

void	dfs(int px, int py, int level, int sum)
{
	int	x;
	int	y;

	if (level == 3)
	{
		if (sum > max_sum)
			max_sum = sum;
		return ;
	}
	else
	{
		for (int j = 0; j < 4; j++)
		{
			x = px + dx[j];
			y = py + dy[j];
			if (x >= 0 && x < m && y >= 0 && y < m && visited[x][y] == false)
			{
				visited[x][y] = true;
				dfs(x, y, level + 1, sum + map[x][y]);
				visited[x][y] = false;
			}
		}
	}
}

void		check_fuck(int px, int py)
{
	int	sum;
	int x;
	int y;

	for (int i = 0; i < 4; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++)
		{
			x = px + tx[i][j];
			y = py + ty[i][j];
			if (x < n && x >= 0 && y < m && y >= 0)
				sum += map[x][y];
			else
				break ;
		}
		if (sum > max_sum)
			max_sum = sum;
	}	
}

int 	main(void)
{
	cin >> n >> m;	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = true;
			dfs(i, j, 0, map[i][j]);
			visited[i][j] = false;
			check_fuck(i, j);
		}
	}
	cout << max_sum;
	return (0);
}
