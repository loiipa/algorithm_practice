#include <iostream>
using namespace std;

void	order(int n, int start, int end, int via)
{
	if (n == 1)
		printf("%d %d\n", start, end);
	else
	{
		order(n-1, start, via, end);
		printf("%d %d\n", start, end);
		order(n-1, via, end, start);
	}
	return ;
}

int main(void)
{
	int n;
	cin >> n;
	printf("%d\n", (1 << n) - 1);
	order(n, 1, 3, 2);
	return 0;
}
