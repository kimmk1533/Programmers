#include <string>
#include <vector>
#include <queue>
using namespace std;

int graph[101][101];

int solution(int n, vector<vector<int>> results)
{
	int answer = 0;

	// 승패 정보 초기화
	for (int i = 0; i < results.size(); ++i)
	{
		int winner = results[i][0];
		int loser = results[i][1];

		// winner는 loser에게 승리(1)
		graph[winner][loser] = 1;
		// loser는 winner에게 패배(-1)
		graph[loser][winner] = -1;
	}

	// 플로이드 와샬 알고리즘으로 정보 업데이트
	for (int m = 1; m <= n; ++m)
	{
		for (int s = 1; s <= n; ++s)
		{
			for (int e = 1; e <= n; ++e)
			{
				// s가 m한테 승리하고, m이 e한테 승리한다면
				if (graph[s][m] == 1 && graph[m][e] == 1)
				{
					// s는 e랑 싸워볼 필요도 없이 승리함
					graph[s][e] = 1;
					// 마찬가지로 e는 s에게 무조건 패배함
					graph[e][s] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		bool flag = false;

		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;

			if (graph[i][j] == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag == false)
			++answer;
	}

	return answer;
}

#include <iostream>

int main()
{
	/*solution(5, {
		{ 4, 3 },
		{ 4, 2 },
		{ 3, 2 },
		{ 1, 2 },
		{ 2, 5 },
		});*/

	solution(3,
		{
			{ 1, 2 },
			{ 2, 3 },
		});

	return 0;
}