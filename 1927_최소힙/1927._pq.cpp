#include <queue>
#include <stdio.h>
using namespace std;

int	main(void)
{
	priority_queue<int, vector<int>, greater<int> >		pq;
	int		n;
	int		x;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0 && pq.empty()) {
			printf("%d\n", 0);
		}
		else if (x == 0 && !pq.empty()) {
			printf("%d\n", pq.top());
			pq.pop();
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}
