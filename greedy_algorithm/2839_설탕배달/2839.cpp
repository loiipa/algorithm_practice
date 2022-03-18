#include <iostream>
using namespace std;

int main (void) {
	int		n, num_5 = 0;
	cin >> n;
	while (5 * num_5 < n)
		num_5++;
	if (5 * num_5 == n) {
		cout << num_5;
		return 0;
	}
	while (--num_5 >= 0) {
		if ((n - 5*num_5) % 3 == 0) {
			cout << num_5 + (n - 5*num_5) / 3;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
