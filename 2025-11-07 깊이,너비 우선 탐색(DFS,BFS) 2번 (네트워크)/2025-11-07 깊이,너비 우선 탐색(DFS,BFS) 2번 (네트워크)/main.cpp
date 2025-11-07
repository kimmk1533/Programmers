#include <string>
#include <vector>

using namespace std;

bool visited[200];

void dfs(int n, vector<vector<int>>& computers, int computer)
{
	visited[computer] = true;

	for (int i = 0; i < n; ++i)
	{
		// 이미 방문한 컴퓨터는 제외
		if (visited[i] == true)
			continue;
		// 연결되지 않은 컴퓨터 제외
		if (computers[computer][i] == 0)
			continue;

		dfs(n, computers, i);
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == true)
			continue;

		dfs(n, computers, i);

		++answer;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(4,
		{
			{ 1, 1, 0, 1 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 1, 0, 1, 1 },
		});

	return 0;
}