#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
	rocks.push_back(0);
	rocks.push_back(distance);

	sort(rocks.begin(), rocks.end());

	int size = rocks.size();
	int answer = 0;

	// 바위 사이의 거리의 최솟값을 이분탐색으로 찾기
	// 최솟값 (나올 수 있는 거리의 최솟값 중 최솟값)
	int left = 0;
	// 최댓값 (나올 수 있는 거리의 최솟값 중 최댓값)
	int right = distance;
	// 현재 확인하는 중인 나올 수 있는 거리의 최솟값
	int mid = (left + right) >> 1;

	// 제거한 돌의 갯수
	int cnt = 0;
	// 제거되지 않은 마지막 바위의 위치
	int lastPos = 0;

	while (left <= right)
	{
		cnt = 0;
		lastPos = 0;

		for (int i = 1; i <= size - 1; ++i)
		{
			if (rocks[i] - lastPos < mid)
			{
				++cnt;
				continue;
			}
			lastPos = rocks[i];
		}

		if (cnt <= n)
		{
			left = mid + 1;
			answer = max(answer, mid);
		}
		else
			right = mid - 1;

		mid = (left + right) >> 1;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(25, { 2, 14, 11, 21, 17 }, 2) << "\n";
	cout << solution(10, { 3, 5, 7 }, 2);

	return 0;
}