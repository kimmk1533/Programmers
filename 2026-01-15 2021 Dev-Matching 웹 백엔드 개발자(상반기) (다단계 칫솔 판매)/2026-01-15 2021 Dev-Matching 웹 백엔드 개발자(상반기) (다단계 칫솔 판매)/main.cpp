#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	string name = "";
	int cost = 0;
	string parent = "";
	vector<string> childs;
};

map<string, int> indices;
vector<Node> tree;

void addMoney(Node& node, int money)
{
	int parentMoney = money * 0.1f;

	if (parentMoney > 0)
	{
		node.cost += money - parentMoney;
		addMoney(tree[indices[node.parent]], parentMoney);
	}
	else
	{
		node.cost += money;
	}
}

void dfs(vector<int>& answer, Node& node, const vector<string>& seller, const vector<int>& amount)
{
	for (const string& child : node.childs)
		dfs(answer, tree[indices[child]], seller, amount);

	for (int i = 0; i < seller.size(); ++i)
	{
		if (node.name != seller[i])
			continue;

		addMoney(node, amount[i] * 100);
	}

	answer[indices[node.name]] = node.cost;
}

vector<int> solution(vector<string> childs, vector<string> parents, vector<string> seller, vector<int> amount)
{
	const int n = childs.size();

	indices.clear();
	indices.insert({ "-", 0 });
	for (int i = 0; i < n; ++i)
		indices.insert({ childs[i], i + 1 });

	tree.clear();
	tree.resize(n + 1);
	for (int i = 0; i < n; ++i)
	{
		tree[i + 1].name = childs[i];
		tree[i + 1].parent = parents[i];
		tree[indices[parents[i]]].childs.push_back(childs[i]);
	}
	vector<int> answer(n + 1);
	dfs(answer, tree[0], seller, amount);
	answer.erase(answer.begin());
	return answer;
}

#include <iostream>

int main()
{
	for (auto answer : solution(
		{
			"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"
		},
		{
			"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"
		},
		{
			"young", "john", "tod", "emily", "mary"
		},
		{
			12, 4, 2, 5, 10
		}
		))
		cout << answer << " ";
	cout << endl;

	for (auto answer : solution(
		{
			"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"
		},
		{
			"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"
		},
		{
			"sam", "emily", "jaimie", "edward"
		},
		{
			2, 3, 5, 4
		}
		))
		cout << answer << " ";
	cout << endl;

	return 0;
}