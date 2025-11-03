#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;

	vector<int> clothes;
	clothes.assign(n, 1);

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int index : lost)
	{
		--clothes[index - 1];
	}
	for (int index : reserve)
	{
		++clothes[index - 1];
	}

	for (int i = 0; i < lost.size(); ++i)
	{
		int index = lost[i] - 1;

		if (clothes[index] >= 1)
			continue;

		if (index - 1 >= 0 &&
			clothes[index - 1] == 2)
		{
			--clothes[index - 1];
			++clothes[index];
		}
		else if (index + 1 < n &&
			clothes[index + 1] == 2)
		{
			--clothes[index + 1];
			++clothes[index];
		}
	}

	for (int count : clothes)
	{
		if (count >= 1)
			++answer;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(5, vector<int> { 5, 3, 1 }, vector<int> { 3, 4 });

	return 0;
}