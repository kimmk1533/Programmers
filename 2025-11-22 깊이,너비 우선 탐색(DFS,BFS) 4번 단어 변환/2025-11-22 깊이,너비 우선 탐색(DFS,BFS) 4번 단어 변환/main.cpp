#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool check(string curr, string word)
{
	int cnt = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		if (curr[i] != word[i])
		{
			if (++cnt >= 2)
				break;
		}
	}
	return cnt == 1;
}

int solution(string begin, string target, vector<string> words)
{
	queue<pair<string, int>> wordQ;
	unordered_map<string, bool> visited;
	pair<string, int> curr;

	wordQ.push({ begin, 0 });
	while (wordQ.empty() == false)
	{
		curr = wordQ.front(); wordQ.pop();

		if (curr.first == target)
			return curr.second;

		for (string word : words)
		{
			if (visited[word])
				continue;

			if (check(curr.first, word))
			{
				wordQ.push({ word, curr.second + 1 });
				visited[word] = true;
			}
		}
	}

	return 0;
}

#include <iostream>

int main()
{
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << "\n";
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << "\n";

	return 0;
}