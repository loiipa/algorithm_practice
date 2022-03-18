#include <iostream>

using namespace std;

int		answer_box(int a, int b)
{
	int		remainder = 1;

	a %= 10;
	if (a == 0)
		a = 10;
		
	b %= 4;
	if (b == 0)
		b = 4;

	for (int i = 0; i < b; i++)
	{
		remainder = (remainder * a) % 10;
		if (remainder == 0)
			remainder = 10;
	}
	return remainder;
}

int		main(void)
{
	int 	num, a, b;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		cout << answer_box(a, b) << endl;
	}
}
// 1 - 1	1	1	1	1	1	1	1
// 2 - 2	4	8	6	2	4	8	6
// 3 - 3	9	7	1	3	9	7	1
// 4 - 4	6	4	6	4	6	4	6
// 5 - 5	5	5	5	5	5	5	5
// 6 - 6	6	6	6	6	6	6	6
// 7 - 7	9	3	1	7	9	3	1
// 8 - 8	4	2	6	8	4	2	6
// 9 - 9	1	9	1	9	1	9	1
//10 - 10	10	10	10	10	10	10	10
