#include <string>
#include <vector>
using namespace std;

int dp[100001];

int solution(int n, vector<int> money)
{
	dp[0] = 1;

	for (int i = 0; i < money.size(); ++i)
		for (int j = money[i]; j <= n; ++j)
			dp[j] += dp[j - money[i]];

	return dp[n] % 1000000007;
}

#include <iostream>

int main()
{
	cout << solution(5, { 1, 2, 5 });

	return 0;
}