#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name)
{
	int answer = 0;

	for (char c : name)
		answer += min(c - 'A', 'Z' - c + 1);

	// 쭉 오른쪽으로만 가는 이동 횟수
	int cnt = name.size() - 1;
	// 오른쪽으로 가다가 왼쪽으로 유턴해서 가는 이동 횟수
	int cnt2 = cnt;
	// 왼쪽으로 가다가 오른쪽으로 유턴해서 가는 이동 횟수
	int cnt3 = cnt;

	int size = name.size();
	int start = -1, end = -1;

	// 반환점 찾기
	for (start = 0; start < size; ++start)
	{
		for (end = start + 1; end < size; ++end)
		{
			if (name[end] != 'A')
				break;
		}

		// 2번 방법 구하기
		cnt2 = (start << 1) + (size - end);

		// 3번 방법 구하기
		cnt3 = ((size - end) << 1) + start;

		cnt = min<int>({ cnt, cnt2, cnt3 });
	}

	return answer + cnt;
}

#include <iostream>

int main()
{
	cout << solution("CANAAAAANAN");
}