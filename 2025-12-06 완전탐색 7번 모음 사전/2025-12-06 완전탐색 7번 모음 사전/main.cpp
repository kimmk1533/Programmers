#include <string>
#include <vector>
using namespace std;

int answer = 0;
string alphabet[5] { "A", "E", "I", "O", "U" };
int used_count[5] { 0, };

int dfs(string curr, const string& word)
{
	if (curr == word)
		return answer;
	if (curr.size() > 5)
		return 0;

	++answer;

	for (int i = 0; i < 5; ++i)
	{
		if (used_count[i] == 5)
			continue;

		++used_count[i];
		if (0 != dfs(curr + alphabet[i], word))
			return answer;
		--used_count[i];
	}

	return 0;
}

int solution(string word)
{
	return dfs("", word);
}

#include <iostream>

int main()
{
	cout << solution("AAAAE");

	return 0;
}