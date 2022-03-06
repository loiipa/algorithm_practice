#include <iostream>

int	main(void)
{
	int	hour, min, time;

	std::cin >> hour >> min >> time;
	hour = (hour + time / 60) % 24;
	min += time % 60;
	if (min >= 60)
	{
		++hour;
		min -= 60;
	}
	if (hour >= 24)
		hour -= 24;

	std::cout << hour << " " << min;
}
