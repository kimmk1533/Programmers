#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[17];

int dfs(vector<int>& info, int node, int sheepCount, int wolfCount, vector<int> nexts)
{
	(info[node] == 0) ? ++sheepCount : ++wolfCount;
	if (sheepCount <= wolfCount)
		return sheepCount;

	nexts.erase(find(nexts.begin(), nexts.end(), node));
	for (int child : edge[node])
		nexts.push_back(child);

	int maxSheep = sheepCount;
	for (int next : nexts)
		maxSheep = max(maxSheep, dfs(info, next, sheepCount, wolfCount, nexts));

	return maxSheep;
}

int solution(vector<int> info, vector<vector<int>> edges)
{
	for (vector<int> e : edges)
		edge[e[0]].push_back(e[1]);

	return dfs(info, 0, 0, 0, { 0, });
}

#include <iostream>

int main()
{
	cout << solution({ 0,0,1,1,1,0,1,0,1,0,1,1 }, { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} }) << endl;

	return 0;
}