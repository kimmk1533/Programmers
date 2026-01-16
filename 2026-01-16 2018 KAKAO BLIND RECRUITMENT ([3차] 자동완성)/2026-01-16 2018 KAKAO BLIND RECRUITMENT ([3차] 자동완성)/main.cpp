#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findIndex(const string& a, const string& b)
{
	const int n = min(a.size(), b.size());
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i])
			return i;
	}
	return n;
}

int solution(vector<string> words)
{
	sort(words.begin(), words.end());

	const int n = words.size();
	int index = findIndex(words[0], words[1]);
	int answer = (index == words[0].size() ? index : index + 1);
	for (int i = 1; i < n - 1; ++i)
	{
		string prev = words[i - 1];
		string curr = words[i];
		string next = words[i + 1];

		index = max(findIndex(prev, curr), findIndex(curr, next));
		answer += (index == curr.size() ? index : index + 1);
	}
	index = findIndex(words[n - 1], words[n - 2]);
	answer += (index == words[n - 1].size() ? index: index + 1);
	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ "ab", "abc" }) << endl;
	cout << solution(
		{
			"go",
			"gone",
			"guild",
		}
		) << endl;
	cout << solution(
		{
			"abc",
			"def",
			"ghi",
			"jklm",
		}
		) << endl;
	cout << solution(
		{
			"word",
			"war",
			"warrior",
			"world",
		}
		) << endl;

	return 0;
}