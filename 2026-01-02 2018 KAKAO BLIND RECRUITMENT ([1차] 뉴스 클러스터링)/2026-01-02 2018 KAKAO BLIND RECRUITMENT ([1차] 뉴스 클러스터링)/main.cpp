#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2)
{
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	string origin[2] { str1, str2 };
	vector<string> set[2];

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < origin[i].size() - 1; ++j)
		{
			string tempSet = origin[i].substr(j, 2);

			if (tempSet[0] >= 'a' && tempSet[0] <= 'z' &&
				tempSet[1] >= 'a' && tempSet[1] <= 'z')
				set[i].push_back(tempSet);
		}

		sort(set[i].begin(), set[i].end());
	}

	if (set[0].size() == 0 && set[1].size() == 0)
		return 65536;

	vector<string> setU, setI;

	set_union(set[0].begin(), set[0].end(), set[1].begin(), set[1].end(), back_inserter(setU));
	set_intersection(set[0].begin(), set[0].end(), set[1].begin(), set[1].end(), back_inserter(setI));

	return ((float)setI.size() / setU.size()) * 65536;
}

int main()
{
	cout << solution("FRANCE", "french");

	return 0;
}