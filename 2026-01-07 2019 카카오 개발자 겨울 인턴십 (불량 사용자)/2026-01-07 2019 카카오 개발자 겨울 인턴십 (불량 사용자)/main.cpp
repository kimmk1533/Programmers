#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isSame(const string& user, const string& bannedId)
{
	if (user.size() != bannedId.size())
		return false;

	for (int i = 0; i < user.size(); ++i)
	{
		if (bannedId[i] == '*')
			continue;
		if (user[i] != bannedId[i])
			return false;
	}

	return true;
}

set<vector<int>> answer;

void dfs(const vector<vector<int>>& db, vector<int> v, int level)
{
	if (level == db.size())
	{
		sort(v.begin(), v.end());
		if (unique(v.begin(), v.end()) == v.end())
			answer.insert(v);
		return;
	}

	for (int i = 0; i < db[level].size(); ++i)
	{
		v.push_back(db[level][i]);
		dfs(db, v, level + 1);
		v.pop_back();
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	const int banSize = banned_id.size();

	vector<vector<int>> db(banSize);
	for (int i = 0; i < banSize; ++i)
		for (int j = 0; j < user_id.size(); ++j)
			if (isSame(user_id[j], banned_id[i]) == true)
				db[i].push_back(j);

	dfs(db, {}, 0);
	return answer.size();
}

#include <iostream>

int main()
{
	//cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" }) << endl;
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" }) << endl;
	cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" }) << endl;

	return 0;
}