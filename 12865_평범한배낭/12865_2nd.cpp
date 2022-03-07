#include <iostream>
#include <vector>

using namespace std;


int	main(void)
{
	int n, k, p1, p2;
	vector<int>				w(100);
	vector<int>				v(100);
	vector<vector<int> >	save(101, vector<int>(100001));

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
			save[i+1][j] = save[i][j];
		for (int j = 0; j <= k - w[i]; j++)
		{
			if (save[i][j+w[i]] < save[i][j] + v[i])
				save[i+1][j+w[i]] = save[i][j] + v[i];
		}
	}
	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= k; j++)
	// 	{
	// 		cout << save[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	cout << save[n][k];
	return 0;
}
