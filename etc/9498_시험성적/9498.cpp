#include <iostream>

int		main(void)
{
	int		score;
	std::cin >> score;

	switch(score)
	{
		case 90 ... 100:
			std::cout << "A";
			break;
		case 80 ... 89:
			std::cout << "B";
			break;
		case 70 ... 79:
			std::cout << "C";
			break;
		case 60 ... 69:
			std::cout << "D";
			break;
		default:
			std::cout << "F";
			break;
	}
}
