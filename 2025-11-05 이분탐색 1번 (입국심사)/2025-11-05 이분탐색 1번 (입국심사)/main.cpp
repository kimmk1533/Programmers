#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());

	int size = times.size();
	ull low = times[0], high = times[size - 1] * n, mid = (low + high) >> 1;
	ull answer = high;

	ull total = 0;
	while (low <= high)
	{
		total = 0;

		for (int i = 0; i < size; ++i)
		{
			ull t = times[i];

			total += mid / t;
			if (total >= n)
			{
				answer = mid;
				break;
			}
		}

		if (total >= n)
			high = mid - 1;
		else
			low = mid + 1;

		mid = (low + high) >> 1;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(1, { 5 });

	return 0;
}