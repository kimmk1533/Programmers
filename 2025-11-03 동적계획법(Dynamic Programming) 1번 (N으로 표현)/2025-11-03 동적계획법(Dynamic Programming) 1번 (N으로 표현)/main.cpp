#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<set<int>> dp(9);

int solution(int N, int number)
{
	if (N == number)
		return 1;

	dp[1].insert(N);
	for (int i = 2; i <= 8; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			for (int a : dp[j])
			{
				for (int b : dp[i - j])
				{
					dp[i].insert(a + b);
					dp[i].insert(a - b);
					dp[i].insert(a * b);
					if (b != 0)
						dp[i].insert(a / b);

					dp[i].insert(b - a);
					if (a != 0)
						dp[i].insert(b / a);
				}
			}
		}

		// 제곱수
		int powNum = N;
		for (int p = 1; p < i; ++p)
		{
			powNum += N * pow(10, p);
		}
		dp[i].insert(powNum);

		for (int num : dp[i])
		{
			if (num == number)
				return i;
		}
	}

	return -1;
}

#include <iostream>

int main()
{
	cout << solution(5, 12);

	return 0;
}