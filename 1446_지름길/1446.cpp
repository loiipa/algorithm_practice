#include <iostream>
#include <map>
#include <set>

bool	is_shortcut(int &loadLength, int &shortStart, int &shortEnd, int &shortLength)
{
	if (loadLength < shortEnd)
		return false;
	else if (shortEnd - shortStart <= shortLength)
		return false;
	return true;
}

// 일단 c스타일로 풀어보기
int	main(void)
{
	int		shortNum, loadLength;
	int		shortStart, shortEnd, shortLength;
	int		endPrev, lengthTmp;
	std::map<std::pair<int, int>, int>	mShortCut;
	std::set<int>						sNode;
	std::pair<int, int>					p, pPrev; 

	// 입력
	std::cin >> shortNum >> loadLength;
	sNode.insert(0);
	sNode.insert(loadLength);
	for (int i = 0; i < shortNum; i++)
	{
		std::cin >> shortStart >> shortEnd >> shortLength;

		p = std::make_pair(shortStart, shortEnd);

		if (is_shortcut(loadLength, shortStart, shortEnd, shortLength) == true)
		{
			if (shortLength == 0)
				--shortLength;
			if (mShortCut[p] != 0 && mShortCut[p] > shortLength)
				mShortCut[p] = shortLength;
			else if (mShortCut[p] == 0)
				mShortCut[p] = shortLength;
			sNode.insert(shortStart);
			sNode.insert(shortEnd);
		}
	}

	// 최단거리 구하기
	endPrev = 0;
	pPrev = std::make_pair(0, 0);
	for (int end : sNode)
	{
		for (int start : sNode)
		{
			if (start >= end)
				continue;
			p = std::make_pair(start, end);
			if (start == 0 && mShortCut[p] == 0)
				mShortCut[p] = mShortCut[pPrev] + (end - endPrev);
			else if (mShortCut[p] != 0)
			{
				if (mShortCut[p] == -1)
					++mShortCut[p];
				if (start == 0)
					lengthTmp = mShortCut[pPrev] + (end - endPrev);
				else if (start != 0)
					lengthTmp = mShortCut[std::make_pair(0, start)] + mShortCut[p];
				if (lengthTmp < mShortCut[std::make_pair(0, end)])
					mShortCut[std::make_pair(0, end)] = lengthTmp;
			}
		}
		endPrev = end;
		pPrev = std::make_pair(0, end);
	}

	// 출력
	std::cout << mShortCut[std::make_pair(0, loadLength)];
	return 0;
}

// 1차시도 - 85%에 틀림..
// 2차시도 - 85%에 틀림..
// 3차시도 - 성공
// 예외사항
/*
2 100
0 100 90
1 99 2
*/
