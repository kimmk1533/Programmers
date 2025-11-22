#include <vector>
#include <string>
using namespace std;

// 메커니즘 참고: https://school.programmers.co.kr/questions/64429
int solution(vector<string> arr)
{
	int a0 = stoi(arr[0]);
	int a0Index = 0;
	for (int i = 0; i < arr.size() - 2; i += 2)
	{
		a0Index = i;
		if (arr[i + 1] == "-")
			break;

		a0 += stoi(arr[i + 2]);
	}

	int maxTail = 0, minTail = 0;
	int tail = 0;

	for (int index = arr.size() - 1; index > a0Index; index -= 2)
	{
		int num = stoi(arr[index]);
		if (arr[index - 1] == "-")
		{
			int maxSub = -num + tail;
			int minSub = -(num + tail);

			int tempMax = maxTail;
			maxTail = max(maxSub + maxTail, minSub - minTail);
			minTail = min(minSub + minTail, minSub - tempMax);

			tail = 0;
			continue;
		}

		tail += num;
	}

	return a0 + maxTail;
}

#include <iostream>

int main()
{
	cout << solution({ "0", "-", "6", "+", "5", "+", "4", "-", "3", "+", "2", "+", "1" }) << "\n";

	return 0;
}