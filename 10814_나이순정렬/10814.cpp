#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct UserInfo
{
	int userAge;
	int userIndex;
	std::string userName;

	bool operator<(const UserInfo & rhs) const
	{
		if (this->userAge < rhs.userAge)
			return true;
		else if (this->userAge == rhs.userAge)
			return this->userIndex < rhs.userIndex;
		else
			return false;
	}
};

int main()
{
	int userNum = 0;
	std::cin >> userNum;
	std::vector<UserInfo> userVector(userNum);

	for (int i = 0; i < userNum; i++)
	{
		UserInfo userInfo;
		std::cin >> userInfo.userAge >> userInfo.userName;
		userInfo.userIndex = i;
		userVector[i] = std::move(userInfo);
	}

	std::sort(userVector.begin(), userVector.end());
	for (const UserInfo & userInfo : userVector)
		std::cout << userInfo.userAge << ' ' << userInfo.userName << "\n";
}
