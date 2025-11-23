#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<string, int> psi;
typedef pair<int, int> pii;

struct cmpPii
{
	bool operator()(pii& a, pii& b)
	{
		if (a.first == b.first)
			return a.second > b.second;

		return a.first < b.first;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
	map<string, int> genreCount;
	vector<string> genreOrder;
	map<string, priority_queue<pii, vector<pii>, cmpPii>> playCount;

	for (int i = 0; i < genres.size(); ++i)
	{
		genreCount[genres[i]] += plays[i];
		playCount[genres[i]].push({ plays[i], i });
	}

	while (genreCount.empty() == false)
	{
		pair<string, int> temp = *max_element(genreCount.begin(), genreCount.end(), [](psi a, psi b)
			{
				return a.second < b.second;
			});
		genreOrder.push_back(temp.first);
		genreCount.erase(temp.first);
	}

	vector<int> answer;

	for (string genre : genreOrder)
	{
		if (playCount[genre].size() == 1)
			answer.push_back(playCount[genre].top().second);
		else if (playCount[genre].size() > 1)
		{
			answer.push_back(playCount[genre].top().second);
			playCount[genre].pop();
			answer.push_back(playCount[genre].top().second);
		}
	}

	return answer;
}

#include <iostream>

int main()
{
	vector<int> result = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
	for (int index : result)
		cout << index << " ";

	return 0;
}