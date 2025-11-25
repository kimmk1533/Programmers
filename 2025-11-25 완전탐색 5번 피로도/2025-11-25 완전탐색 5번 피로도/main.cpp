#include <string>
#include <vector>
using namespace std;

bool visited[8];
int maxCnt = -1;

void dfs(int cnt, int k, vector<vector<int>> dungeons)
{
	maxCnt = max(maxCnt, cnt);

	if (cnt >= dungeons.size())
		return;

	for (int i = 0; i < dungeons.size(); ++i)
	{
		if (visited[i])
			continue;
		if (dungeons[i][0] > k)
			continue;

		visited[i] = true;
		dfs(cnt + 1, k - dungeons[i][1], dungeons);
		visited[i] = false;
	}
}

int solution(int k, vector<vector<int>> dungeons)
{
	dfs(0, k, dungeons);

	return maxCnt;
}

#include <iostream>

int main()
{
	cout << solution(80, { { 80, 20 }, { 50, 40 }, { 30, 10 } }) << "\n";

	return 0;
}