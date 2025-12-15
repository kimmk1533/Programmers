#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
	set<string> s;
	for (int index = 0; index < words.size(); ++index)
	{
		if (s.insert(words[index]).second == false ||
			(index > 0 && words[index - 1].back() != words[index].front()))
			return { index % n + 1, index / n + 1 };
	}

	return { 0, 0 };
}

#include <iostream>

int main()
{
	for (int i : solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" }))
		cout << i << " ";

	return 0;
}