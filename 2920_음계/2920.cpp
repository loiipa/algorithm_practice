#include <iostream>

using namespace std;

int main(void)
{
	int n, sound = 0;

	for (int i = 0; i < 8; i++)
	{
		cin >> n;
		sound = sound*10 + n;
	}
	if (sound == 12345678)
		cout << "ascending";
	else if (sound == 87654321)
		cout << "descending";
	else
		cout << "mixed";
	return 0;
}
