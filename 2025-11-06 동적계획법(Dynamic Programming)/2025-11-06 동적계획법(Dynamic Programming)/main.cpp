#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle)
{
	int size = triangle.size();
	vector<vector<int>> sum(size);

	for (int i = 0; i < triangle[size - 1].size(); ++i)
	{
		sum[size - 1].push_back(triangle[size - 1][i]);
	}

	for (int i = size - 1; i > 0; --i)
	{
		for (int j = 0; j < sum[i].size() - 1; ++j)
		{
			int left = sum[i][j], right = sum[i][j + 1];

			sum[i - 1].push_back(triangle[i - 1][j] + max(left, right));
		}
	}

	return *max_element(sum[0].begin(), sum[0].end());
}

#include <iostream>

int main()
{
	cout << solution(
		{
			{      7 },
			{    3, 8 },
			{   8, 1, 0 },
			{  2, 7, 4, 4 },
			{ 4, 5, 2, 6, 5 },
		}
		);

	/*
	*                                 7
	*                 10,                            15
	*         18,            11,              16,            15
	*    20,     25,     18,     15,     23,     20,     19,     19
	*  24, 25, 30, 27, 23, 20,
	*/

	return 0;
}