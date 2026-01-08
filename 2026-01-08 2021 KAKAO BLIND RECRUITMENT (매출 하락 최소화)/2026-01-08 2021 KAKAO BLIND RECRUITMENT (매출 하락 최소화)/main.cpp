#include <string>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<int> sales;
vector<vector<int>> team;

void dfs(const int v)
{
	// 본인 참여
	dp[v][1] = sales[v];

	if (team[v].empty())
		return;

	int minGap = 1e9;

	for (auto child : team[v])
	{
		dfs(child);

		// 자식(팀원들)이 참여한 경우 추가
		dp[v][0] += min(dp[child][0], dp[child][1]);
		dp[v][1] += min(dp[child][0], dp[child][1]);

		minGap = min(minGap, max(0, dp[child][1] - dp[child][0]));
	}

	// 본인 미참여
	dp[v][0] += minGap;
}

int solution(vector<int> _sales, vector<vector<int>> links)
{
	dp.assign(_sales.size() + 1, vector<int>(2));
	sales.resize(_sales.size() + 1);
	for (int i = 0; i < _sales.size(); ++i)
		sales[i + 1] = _sales[i];
	team.assign(_sales.size() + 1, vector<int>());
	for (auto link : links)
		team[link[0]].push_back(link[1]);

	dfs(1);

	return min(dp[1][0], dp[1][1]);
}

#include <iostream>

int main()
{
	cout << solution({ 14, 17, 15, 18, 19, 14, 13, 16, 28, 17 }, { {10, 8}, {1, 9 }, {9,7},{5,4},{1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2} }) << endl;
	cout << solution({ 5, 6, 5, 3, 4 }, { {2, 3}, {1, 4}, {2, 5}, {1, 2} }) << endl;
	cout << solution({ 5, 6, 5, 1, 4 }, { {2, 3}, {1, 4}, {2, 5}, {1, 2} }) << endl;
	cout << solution({ 10, 10, 1, 1 }, { {3, 2}, {4, 3}, {1, 4} }) << endl;

	return 0;
}