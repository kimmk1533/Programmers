#include <vector>
using namespace std;

vector<vector<int>> dp;

int solution(vector<vector<int>> matrix)
{
	const int n = matrix.size();
	dp.assign(n, vector<int>(n, 2000000000));
	for (int i = 0; i < n; ++i)
		dp[i][i] = 0;

	for (int cnt = 1; cnt < n; ++cnt)
	{
		for (int s = 0; s < n - cnt; ++s)
		{
			int e = s + cnt;

			for (int k = s; k < e; ++k)
			{
				dp[s][e] = min(dp[s][e], dp[s][k] + dp[k + 1][e] + (matrix[s][0] * matrix[k][1] * matrix[e][1]));
			}
		}
	}

	return dp[0][n - 1];
}

#include <iostream>

int main()
{
	cout << solution({ { 9, 10 }, { 10, 9 }, { 9, 1 }, { 1, 2 } });

	return 0;
}