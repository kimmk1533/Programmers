#include <string>
#include <vector>
using namespace std;

// 해당 위치까지 최소거리로 오는 경우의 수
long long dp_count[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{
	for (int i = 0; i < puddles.size(); ++i)
		dp_count[puddles[i][1]][puddles[i][0]] = -1;

	dp_count[1][1] = 1;
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			if (dp_count[y][x] == -1)
				continue;

			dp_count[y][x] += max(0ll, dp_count[y - 1][x]) + max(0ll, dp_count[y][x - 1]);
			dp_count[y][x] %= 1000000007;
		}
	}

	return dp_count[n][m];
}

#include <iostream>

int main()
{
	cout << solution(4, 3, {
		{ 2, 2 },
		}) << "\n";

	return 0;
}