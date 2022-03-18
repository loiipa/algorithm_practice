#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int	fixedNum(vector<vector<bool> > & fix)
{
	int num = 0;
	for (vector<bool> vBool : fix)
		for (bool b : vBool)
			if (b == true)
				++num;
	return num;
}

int	fixedNum(vector<vector<bool> > & fix, int y, int x)
{
	int num = 0;

	for (int i = y; i < y+8; i++)
		for (int j = x; j < x+8; j++)
			if (fix[i][j] == true)
				++num;
	return num;
}

int	main(void)
{
	int 				n, m;
	int 				answer = 128;
	vector<string>		board;
	string				s;

	cin >> n >> m;

	vector<vector<bool> >	fixB(n, vector<bool>(m));
	vector<vector<bool> >	fixW(fixB);

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		board.push_back(s);
	}

	/* 바꿀지점 기록 */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 좌측 상단이 B인 경우
			if ((i + j) % 2 == 0 && board[i][j] == 'B')
				fixB[i][j] = true;
			else if ((i + j) % 2 == 1 && board[i][j] == 'W')
				fixB[i][j] = true;
			// 좌측 상단이 W인 경우
			if ((i + j) % 2 == 0 && board[i][j] == 'W')
				fixW[i][j] = true;
			else if ((i + j) % 2 == 1 && board[i][j] == 'B')
				fixW[i][j] = true;
		}
	}

	/* 고칠게 없을 때 */
	if (fixedNum(fixB) == 0 || fixedNum(fixW) == 0)
	{
		cout << 0;
		return 0;
	}

	/* 판별 */
	for (int i = 0; i <= n-8; i++)
		for (int j = 0; j <= m-8; j++)
			answer = min(answer, min(fixedNum(fixB, i, j), fixedNum(fixW, i, j)));
	cout << answer;

	return 0;
}

