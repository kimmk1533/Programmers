#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge)
{
	int answer = 0;

	vector<set<int>> nodes(n + 1);
	for (int i = 0; i < edge.size(); ++i)
	{
		int first = edge[i][0];
		int second = edge[i][1];

		nodes[first].insert(second);
		nodes[second].insert(first);
	}

	// 다음으로 갈 노드 저장할 큐
	queue<int> q;
	// 1번 노드부터의 거리
	vector<int> dist(n + 1);
	dist.assign(n + 1, numeric_limits<int>::max());
	// 방문 여부
	vector<bool> visited(n + 1);
	visited.assign(n + 1, false);

	dist[1] = 0;

	q.push(1);
	while (!q.empty())
	{
		int currNode = q.front(); q.pop();

		if (visited[currNode] == true)
			continue;

		for (int node : nodes[currNode])
		{
			if (visited[node] == true)
				continue;

			dist[node] = min<int>(dist[currNode] + 1, dist[node]);

			q.push(node);
		}

		visited[currNode] = true;
	}

	int maxCount = 0;
	for (int i = 1; i < n + 1; ++i)
		maxCount = max<int>(maxCount, dist[i]);

	for (int count : dist)
	{
		if (count == maxCount)
			++answer;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(6, {
		{ 3, 6 },
		{ 4, 3 },
		{ 3, 2 },
		{ 1, 3 },
		{ 1, 2 },
		{ 2, 4 },
		{ 5, 2 },
		});
}