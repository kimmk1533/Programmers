#include <string>
#include <vector>
#include <queue>
using namespace std;

class edge
{
public:
	// 오름차순 정렬(pq)
	bool operator< (edge other) const
	{
		return weight > other.weight;
	}

public:
	int v1;
	int v2;
	int weight;

	edge(int v1, int v2, int weight)
	{
		this->v1 = v1;
		this->v2 = v2;
		this->weight = weight;
	}
};

int solution(int n, vector<vector<int>> costs)
{
	priority_queue<edge> pq;
	for (int i = 0; i < costs.size(); ++i)
		pq.push(edge(costs[i][0], costs[i][1], costs[i][2]));

	int parent[101] { 0, };
	for (int i = 0; i < n; ++i)
		parent[i] = i;

	int answer = 0;
	int edgeCnt = 0;
	while (edgeCnt != n - 1)
	{
		edge edge = pq.top(); pq.pop();

		if (parent[edge.v1] == parent[edge.v2])
			continue;

		int prevParent = max(parent[edge.v1], parent[edge.v2]);
		int currParnet = min(parent[edge.v1], parent[edge.v2]);
		for (int i = 0; i < n; ++i)
		{
			if (parent[i] == prevParent)
				parent[i] = currParnet;
		}
		answer += edge.weight;
		++edgeCnt;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(4,
		{
			{ 0, 1, 3 },
			{ 0, 2, 3 },
			{ 1, 2, 5 },
			{ 1, 3, 1 },
			{ 2, 3, 8 },
		}) << "\n";

	return 0;
}