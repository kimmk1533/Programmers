#pragma region 플로이드 워셜
//#include <string>
//#include <vector>
//using namespace std;
//
//#define INF 1000000
//
//// 그래프
//int dp[200][200];
//
//int solution(int n, int s, int a, int b, vector<vector<int>> fares)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			dp[i][j] = (i == j) ? 0 : INF;
//		}
//	}
//	for (vector<int> fare : fares)
//	{
//		int c = fare[0] - 1;
//		int d = fare[1] - 1;
//		int f = fare[2];
//
//		dp[d][c] = dp[c][d] = f;
//	}
//
//	for (int k = 0; k < n; ++k)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
//			}
//		}
//	}
//
//	int minDist = dp[s - 1][a - 1] + dp[s - 1][b - 1];
//	for (int i = 0; i < n; ++i)
//	{
//		minDist = min(minDist, dp[s - 1][i] + dp[i][a - 1] + dp[i][b - 1]);
//	}
//	return minDist;
//}
#pragma endregion

#pragma region 다익스트라
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000

// 노드의 비용
int priceS[200]; // s => node
int priceA[200]; // node => a
int priceB[200]; // node => b
// 노드 정보
vector<pair<int, int>> nodes[200];

void Dijkstra(int s, int price[])
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s - 1 });

	while (pq.empty() == false)
	{
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (price[curr] < cost)
			continue;

		for (pair<int, int> node : nodes[curr])
		{
			int nCost = node.first;
			int next = node.second;

			if (price[next] > cost + nCost)
			{
				price[next] = cost + nCost;
				pq.push({ price[next], next });
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	for (int i = 0; i < n; ++i)
	{
		priceS[i] = INF;
		priceA[i] = INF;
		priceB[i] = INF;
	}
	priceS[s - 1] = 0;
	priceA[a - 1] = 0;
	priceB[b - 1] = 0;

	for (vector<int> fare : fares)
	{
		int c = fare[0] - 1;
		int d = fare[1] - 1;
		int f = fare[2];

		nodes[c].push_back({ f, d });
		nodes[d].push_back({ f, c });
	}

	Dijkstra(s, priceS);
	Dijkstra(a, priceA);
	Dijkstra(b, priceB);

	int minDist = INF;
	for (int i = 0; i < n; ++i)
	{
		minDist = min(minDist, priceS[i] + priceA[i] + priceB[i]);
	}
	return minDist;
}
#pragma endregion

#include <iostream>

int main()
{
	//cout << solution(6, 4, 6, 2, { {4, 1, 10} ,{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} }) << endl;
	cout << solution(7, 3, 4, 1, { { 5, 7, 9 }, { 4, 6, 4 }, { 3, 6, 1 }, { 3, 2, 3 }, { 2, 1, 6 } }) << endl;

	return 0;
}