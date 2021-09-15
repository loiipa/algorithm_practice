// #include <iostream>
#include <stdio.h>
using namespace std;

int	main(void)
{
	int		n;
	int		index;
	int		arr[1000001]= {0, };

	// cin >> n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// cin >> index;
		scanf("%d", &index);
		arr[index] = 1;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (arr[i] == 0) {
			// cout << i;
			printf("%d", i);
			break;
		}
	}
}
