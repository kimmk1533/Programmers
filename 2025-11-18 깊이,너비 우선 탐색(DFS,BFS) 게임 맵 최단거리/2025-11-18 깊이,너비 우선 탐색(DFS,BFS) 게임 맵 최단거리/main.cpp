#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 해당 위치까지의 최소거리
int dp_distance[101][101];
bool visited[101][101];

const int dir[4][2] =
{
	{ 1, 0 }, // 우
	{ 0, 1 }, // 하
	{ -1, 0 }, // 좌
	{ 0, -1 }, // 상
};
int solution(vector<vector<int>> maps)
{
	queue<tuple<int, int, int>> q;
	int n = maps.size();
	int m = maps[0].size();

	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= m; ++x)
		{
			dp_distance[y][x] = n * m;
			if (maps[y - 1][x - 1] == 0) visited[y][x] = true;
		}
	}

	int x, y, dist;
	q.push(make_tuple(1, 1, 1));
	visited[1][1] = true;
	while (q.empty() == false)
	{
		tuple<int, int, int> point = q.front(); q.pop();

		tie(x, y, dist) = point;

		dp_distance[y][x] = min(dist, dp_distance[y][x]);

		for (int i = 0; i < 4; ++i)
		{
			x = get<0>(point) + dir[i][0];
			y = get<1>(point) + dir[i][1];

			if (x == 0 || x > m ||
				y == 0 || y > n)
				continue;
			if (dp_distance[y][x] < dist + 1)
				continue;
			if (visited[y][x] == true)
				continue;

			q.push(make_tuple(x, y, dist + 1));
			visited[y][x] = true;
		}
	}

	return visited[n][m] == true ? dp_distance[n][m] : -1;
}

#include <iostream>

int main()
{
	cout << solution({
		{ 1,0,1,1,1 },
		{ 1,0,1,0,1 },
		{ 1,0,1,1,1 },
		{ 1,1,1,0,1 },
		{ 0,0,0,0,1 },
		}
		) << "\n";

	/*cout << solution({
		{ 1,0,1,1,1 },
		{ 1,0,1,0,1 },
		{ 1,0,1,1,1 },
		{ 1,1,1,0,0 },
		{ 0,0,0,0,1 },
		}
		) << "\n";*/

	return 0;
}