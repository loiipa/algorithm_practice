#include <iostream>
#include <vector>

using namespace std;

int	main(void)
{
	int 	n, m, trueNum, trueIdx, partyNum, partyIdx;
	int 	answer;

	// 사람수, 파티수, 진실을 아는 사람 체크
	cin >> n >> m >> trueNum;

	vector<int>	trueList(n+1);
	vector<int>	trueRelatedList(n+1);
	vector<vector<int> >	partyList(m);
	
	answer = m;

	for (int i = 0; i < trueNum; i++)
	{
		cin >> trueIdx;
		trueList[trueIdx] = 1;
		trueRelatedList[trueIdx] = 1;
	}

	// 파티 참석자와, 거짓말 가능 유무 체크
	for (int i = 0; i < m; i++)
	{
		cin >> partyNum;
		vector<int>		partyAttendees(partyNum + 1);
		partyAttendees[0] = 1;
		for (int j = 1; j <= partyNum; j++)
		{
			cin >> partyIdx;
			partyAttendees[j] = partyIdx;
			if (trueList[partyIdx] == 1 && partyAttendees[0] == 1)
				partyAttendees[0] = 0;
		}
		partyList[i] = partyAttendees;
	}

	// 거짓말 하면 안되는 사람 추리기
	for (vector<int> v : partyList)
	{
		if (v[0] == 0)
		{
			for (int i = 1; i < v.size(); i++)
				trueRelatedList[v[i]] = 1;
			--answer;
		}
	}

	// 최종 판별
	for (vector<int> v : partyList)
	{
		if (v[0] == 1)
		{
			for (int i = 1; i < v.size(); i++)
			{
				if (trueRelatedList[v[i]] == 1)
				{
					--answer;
					break;
				}
			}
		}
	}	
	cout << answer;
}
