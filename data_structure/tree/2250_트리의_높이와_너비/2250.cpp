#include <iostream>
#include <utility>

using namespace std;
typedef struct		s_tree
{
	int		item;
	s_tree	*left = nullptr;
	s_tree	*right = nullptr;
	s_tree	*root = nullptr; // NULL
}			t_tree;

int		g_min[10001];
int		g_max[10001];

void		make_item(t_tree *s, int *l)
{
	if (!s)
		return ;
	make_item(s->left, l);
	s->item = ++(*l);
	make_item(s->right, l);
}

void		set_max_min(int n)
{
	for (int i = 1; i <= n; i++)
	{
		g_min[i] = 100000;
		g_max[i] = -1;
	}
}

void		check_width(t_tree *s, int level)
{
	if (!s)
		return ;
	if (g_max[level] < s->item)
		g_max[level] = s->item;
	if (g_min[level] > s->item)
		g_min[level] = s->item;
	check_width(s->left, level + 1);
	check_width(s->right, level + 1);
}

t_tree		*check_root(t_tree *s)
{
	t_tree	*tmp = s;

	while (tmp->root)
		tmp = tmp->root;
	return (tmp);
}

int			main(void)
{
	int		n;
	int		root;
	int		lt;
	int		rt;
	int		location = 0;

	pair <int, int> answer;
	t_tree	s[10001];
	t_tree	*ro;

	answer = make_pair(0, 0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> root >> lt >> rt;
		if (lt > 0)
		{
			s[root].left = &(s[lt]);
			s[lt].root = &(s[root]);
		}
		if (rt > 0)
		{
			s[root].right = &(s[rt]);
			s[rt].root = &(s[root]);
		}
	}
	ro = check_root(&(s[1]));
	make_item(ro, &location);
	set_max_min(n);
	check_width(ro, 1);
	for (int i = 1; i <= n; i++)
	{
		if (g_max[i] - g_min[i] + 1 > answer.second)
		{
			answer.first = i;
			answer.second = g_max[i] - g_min[i] + 1;
		}
	}
	cout << answer.first << " " << answer.second;
}
