#include <string>
#include <vector>
using namespace std;

vector<int> func(vector<vector<int>>& arr, int sx, int sy, int xsize, int ysize)
{
	vector<int> answer(2, 0);

	int value = arr[sy][sx];
	bool flag = false;
	for (int y = sy; y < sy + ysize; ++y)
	{
		for (int x = sx; x < sx + xsize; ++x)
		{
			if (arr[y][x] != value)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (flag)
	{
		vector<int> temp;
		int halfX = xsize / 2;
		int halfY = ysize / 2;

		temp = func(arr, sx, sy, halfX, halfY);
		answer[0] += temp[0];
		answer[1] += temp[1];
		temp = func(arr, sx + halfX, sy, halfX, halfY);
		answer[0] += temp[0];
		answer[1] += temp[1];
		temp = func(arr, sx, sy + halfY, halfX, halfY);
		answer[0] += temp[0];
		answer[1] += temp[1];
		temp = func(arr, sx + halfX, sy + halfY, halfX, halfY);
		answer[0] += temp[0];
		answer[1] += temp[1];
	}
	else
	{
		++answer[value];
	}

	return answer;
}

vector<int> solution(vector<vector<int>> arr)
{
	int size = arr.size();

	vector<int> answer = func(arr, 0, 0, size, size);

	return answer;
}

#include <iostream>

int main()
{
	vector<int> answer = solution({ {1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1} });

	for (int i : answer)
	{
		cout << i << " ";
	}

	return 0;
}