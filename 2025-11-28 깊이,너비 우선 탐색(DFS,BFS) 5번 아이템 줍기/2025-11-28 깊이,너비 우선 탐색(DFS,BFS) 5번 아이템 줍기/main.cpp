#include <string>
#include <vector>
#include <queue>
using namespace std;

bool map[102][102];
bool visited[102][102];
const int dx[4] { 0, 1, 0, -1 };
const int dy[4] { 1, 0, -1, 0 };

void resetMap()
{
	for (int y = 2; y <= 100; ++y)
	{
		for (int x = 2; x <= 100; ++x)
		{
			map[y][x] = false;
			visited[y][x] = false;
		}
	}
}
void setValueMap(int minX, int minY, int maxX, int maxY, bool value)
{
	for (int y = minY; y <= maxY; ++y)
	{
		for (int x = minX; x <= maxX; ++x)
		{
			map[y][x] = value;
		}
	}
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
	resetMap();

	for (vector<int> rect : rectangle)
	{
		setValueMap(rect[0] * 2, rect[1] * 2, rect[2] * 2, rect[3] * 2, true);
	}
	for (vector<int> rect : rectangle)
	{
		setValueMap((rect[0] * 2 + 1), (rect[1] * 2 + 1), (rect[2] * 2 - 1), (rect[3] * 2 - 1), false);
	}

	queue<pair<pair<int, int>, int>> bfsQ;
	pair<pair<int, int>, int> curr { { characterX * 2, characterY * 2 }, 0 };
	bfsQ.push(curr);

	while (bfsQ.empty() == false)
	{
		curr = bfsQ.front(); bfsQ.pop();

		int currX = curr.first.first;
		int currY = curr.first.second;

		if (currX == itemX * 2 && currY == itemY * 2)
			break;

		visited[currY][currX] = true;

		for (int i = 0; i < 4; ++i)
		{
			if (visited[currY + dy[i]][currX + dx[i]])
				continue;

			if (map[currY + dy[i]][currX + dx[i]] == true)
				bfsQ.push({ { currX + dx[i], currY + dy[i] }, curr.second + 1 });
		}
	}

	return curr.second / 2;
}

#include <iostream>

int main()
{
	cout << solution({ { 1, 1, 7, 4}, { 3,2,5,5}, {4,3,6,9}, {2,6,8,8} }, 1, 3, 7, 8);

	return 0;
}