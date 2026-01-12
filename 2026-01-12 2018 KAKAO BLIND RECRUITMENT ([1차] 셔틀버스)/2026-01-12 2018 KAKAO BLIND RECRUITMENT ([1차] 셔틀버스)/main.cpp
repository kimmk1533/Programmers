#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define max(a, b) (a > b ? a : b)

string makeTime(int hour, int min)
{
	char strTime[6];
	if (min < 0)
	{
		--hour;
		min += 60;
	}
	snprintf(strTime, sizeof(strTime), "%02d:%02d", hour + (min / 60), (min % 60));
	return strTime;
}

string solution(int n, int t, int m, vector<string> timetable)
{
	map<string, int> bustable;
	for (int i = 0; i < n; ++i)
		bustable.insert({ makeTime(9, i * t), m });

	string answer = "";
	sort(timetable.begin(), timetable.end());
	for (auto time : timetable)
	{
		for (auto& bus : bustable)
		{
			if (bus.second == 0)
				continue;

			if (bus.first >= time)
			{
				if (--bus.second == 0)
					answer = makeTime(stoi(time.substr(0, 2)), stoi(time.substr(3, 2)) - 1);
				break;
			}
		}
	}

	for (auto iter = bustable.rbegin(); iter != bustable.rend(); ++iter)
		if (iter->second != 0)
			return max(answer, iter->first);
	return answer;
}

#include <iostream>

int main()
{
	//cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" }) << " 09:00" << endl;
	cout << solution(2, 10, 2, { "09:10", "09:09", "08:00" }) << " 09:09" << endl;
	cout << solution(2, 10, 2, { "09:09", "09:09", "08:00" }) << " 09:08" << endl;
	//cout << solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" }) << " 08:59" << endl;
	//cout << solution(1, 1, 5, { "00:01", "00:01", "00:01", "00:01", "00:01" }) << " 00:00" << endl;
	//cout << solution(1, 1, 1, { "23:59" }) << " 09:00" << endl;
	//cout << solution(10, 60, 45, { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" }) << " 18:00" << endl;
	//cout << solution(3, 5, 3, { "08:30", "08:40", "09:00", "09:05", "09:05" }) << " 09:10" << endl;

	return 0;
}