#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int>	n(3);
	std::vector<int>	arr(6);
	int					max;

	for (int i = 0; i < 3; i++)
		std::cin >> n[i];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (n[i] == j + 1)
				++arr[j];
		}
	}
	
	max = 0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] == 3)
		{
			std::cout << 10000 + (i+1) * 1000;
			return 0;
		}
		else if (arr[i] == 2)
		{
			std::cout << 1000 + (i+1) * 100;
			return 0;
		}
		else if (arr[i] == 1 && i+1 > max)
			max = i+1;
	}
	std::cout << max * 100;
	return 0;
}
