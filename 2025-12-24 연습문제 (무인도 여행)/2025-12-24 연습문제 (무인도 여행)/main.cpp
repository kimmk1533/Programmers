#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> visited;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

vector<int> solution(vector<string> maps)
{
	int maxWidth = maps[0].size();
	int maxHeight = maps.size();

	vector<int> answer;
	vector<vector<int>> imap(maxHeight, vector<int>(maxWidth, 0));
	visited.assign(maxHeight, vector<bool>(maxWidth, false));

	for (int height = 0; height < maxHeight; ++height)
	{
		for (int width = 0; width < maxWidth; ++width)
		{
			if (maps[height][width] == 'X')
			{
				imap[height][width] = 0;
				visited[height][width] = true;
			}
			else
				imap[height][width] = maps[height][width] - '0';
		}
	}

	for (int height = 0; height < maxHeight; ++height)
	{
		for (int width = 0; width < maxWidth; ++width)
		{
			if (visited[height][width])
				continue;

			visited[height][width] = true;

			int food = 0;
			queue<pair<int, int>> bfsQ;
			bfsQ.push({ height, width });
			while (bfsQ.empty() == false)
			{
				pair<int, int> point = bfsQ.front(); bfsQ.pop();

				food += imap[point.first][point.second];

				for (int i = 0; i < 4; ++i)
				{
					int x = point.second + dx[i];
					int y = point.first + dy[i];

					if (x < 0 || x >= maxWidth)
						continue;
					if (y < 0 || y >= maxHeight)
						continue;
					if (visited[y][x])
						continue;

					visited[y][x] = true;

					bfsQ.push({ y, x });
				}
			}

			answer.push_back(food);
		}
	}

	if (answer.size() == 0)
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

	return answer;
}

#include <iostream>

int main()
{
	vector<int> answer = solution(
		{
			"X591X",
			"X1X5X",
			"X231X",
			"1XXX1",
		});

	for (int i : answer)
		cout << i << " ";

	return 0;
}