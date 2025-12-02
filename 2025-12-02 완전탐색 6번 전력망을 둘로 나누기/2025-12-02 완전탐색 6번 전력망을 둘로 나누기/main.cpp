#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> cache(101, vector<int>());

int dfs(int curr, int parent)
{
	int count = 1;

	for (int node : cache[curr])
	{
		if (node == parent)
			continue;

		count += dfs(node, curr);
	}

	return count;
}

int solution(int n, vector<vector<int>> wires)
{
	for (vector<int> node : wires)
	{
		cache[node[0]].push_back(node[1]);
		cache[node[1]].push_back(node[0]);
	}

	int answer = 100;
	for (vector<int> node : wires)
	{
		int count1 = dfs(node[0], node[1]);
		int count2 = n - count1;

		answer = min(answer, abs(count1 - count2));
	}
	return answer;
}

#include <iostream>

int main()
{
	cout << solution(9, { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} }) << endl;
	cache = vector<vector<int>>(101, vector<int>());
	cout << solution(4, { {1,2},{2,3},{3,4} }) << endl;
	cache = vector<vector<int>>(101, vector<int>());
	cout << solution(7, { {1,2},{2,7},{3,7},{3,4},{4,5},{6,7} }) << endl;

	return 0;
}