#include <iostream>
#include <deque>

int		main(void)
{
	int					n;
	int					item;
	std::deque <int>	dq;
	std::string			s;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
	 	std::cin >> s;
		if (s == "push_front")
		{
			std::cin >> item;
			dq.push_front(item);
		}
		else if (s == "push_back")
		{
			std::cin >> item;
			dq.push_back(item);
		}
		else if (s == "pop_front")
		{
			if (dq.empty())
				std::cout << -1 << std::endl;
			else
			{
				std::cout << dq.front() << std::endl;
				dq.pop_front();
			}

		}
		else if (s == "pop_back")
		{
			if (dq.empty())
				std::cout << -1 << std::endl;
			else
			{
				std::cout << dq.back() << std::endl;
				dq.pop_back();
			}
		}
		else if (s == "size")
		{
			std::cout << dq.size() << std::endl;
		}
		else if (s == "empty")
		{
			if (dq.empty())
				std::cout << 1 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
		else if (s == "front")
		{
			if (dq.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << dq.front() << std::endl;
		}
		else if (s == "back")
		{
			if (dq.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << dq.back() << std::endl;
		}
	}
}
