#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool dfs(string curr, unordered_map<string, vector<string>>& tickets, vector<string>& path, const int& ticketCount)
{
	if (path.size() == ticketCount)
	{
		path.push_back(curr);
		return true;
	}

	path.push_back(curr);
	for (int i = 0; i < tickets[curr].size(); ++i)
	{
		string next = tickets[curr][i];

		tickets[curr].erase(tickets[curr].begin() + i);
		if (true == dfs(next, tickets, path, ticketCount))
			return true;
		tickets[curr].insert(tickets[curr].begin() + i, next);
	}
	path.pop_back();

	return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
	sort(tickets.begin(), tickets.end());
	unordered_map<string, vector<string>> ticket_map;
	for (vector<string> ticket : tickets)
	{
		ticket_map[ticket[0]].push_back(ticket[1]);
	}

	vector<string> answer;

	dfs("ICN", ticket_map, answer, tickets.size());

	return answer;
}

#include <iostream>
// ["ICN","AXA","AUA","ADL","ANU","AUA","ANU","EZE","ADL","EZE","ANU","ICN","AXA","EZE","TIA","ADL","EZE","TIA","AUA","AXA","TIA"]
// ["ICN","AXA","AUA","ADL","ANU","AUA","ANU","EZE","ADL","EZE","ANU","ICN","AXA","EZE","TIA","AUA","AXA","TIA","ADL","EZE","HBA"]
int main()
{
	for (string answer : solution({ {"EZE", "TIA"}, {"EZE", "HBA"}, {"AXA", "TIA"}, {"ICN", "AXA"}, {"ANU", "ICN"}, {"ADL", "ANU"}, {"TIA", "AUA"}, {"ANU", "AUA"}, {"ADL", "EZE"}, {"ADL", "EZE"}, {"EZE", "ADL"}, {"AXA", "EZE"}, {"AUA", "AXA"}, {"ICN", "AXA"}, {"AXA", "AUA"}, {"AUA", "ADL"}, {"ANU", "EZE"}, {"TIA", "ADL"}, {"EZE", "ANU"}, {"AUA", "ANU"} }))
	{
		cout << answer << " ";
	}
	cout << endl;
	for (string answer : solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} }))
	{
		cout << answer << " ";
	}
	cout << endl;

	return 0;
}