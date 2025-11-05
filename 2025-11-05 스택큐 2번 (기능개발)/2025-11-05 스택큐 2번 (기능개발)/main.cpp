#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	vector<int> days;

	days.push_back(ceil((100 - progresses[0]) / speeds[0]));
	for (int i = 1; i < progresses.size(); ++i)
	{
		int day = ceilf((float)(100 - progresses[i]) / speeds[i]);

		if (days[i - 1] > day)
			day = days[i - 1];

		days.push_back(day);
	}

	int cnt, index;
	for (int i = 0; i < days.size(); i += index)
	{
		cnt = 1;
		index = 1;

		int day = days[i];
		for (int j = i + 1; j < days.size(); ++j)
		{
			if (days[j] != day)
				break;

			++cnt;
			++index;
		}

		answer.push_back(cnt);
	}

	return answer;
}

#include <iostream>

int main()
{
	vector<int> answer = solution({ 90, 90 }, { 10, 9 });

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";
	cout << " \n";

	return 0;
}