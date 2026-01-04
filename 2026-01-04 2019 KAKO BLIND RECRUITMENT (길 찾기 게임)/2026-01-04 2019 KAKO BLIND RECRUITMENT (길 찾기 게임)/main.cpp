#include <string>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
	int x;
	int y;

	int data;

	Node* left;
	Node* right;

	Node(int x, int y, int data) : x(x), y(y), data(data)
	{
		left = nullptr;
		right = nullptr;
	}
	bool operator<(const Node& other) const
	{
		if (this->y == other.y)
			return this->x > other.x;

		return this->y < other.y;
	}
	virtual ~Node()
	{
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}

	void SetChild(Node* other)
	{
		if (other->x < x)
		{
			if (left == nullptr)
				left = other;
			else
				left->SetChild(other);
		}
		else
		{
			if (right == nullptr)
				right = other;
			else
				right->SetChild(other);
		}
	}

	void PreOrder(vector<int>& answer)
	{
		answer.push_back(data);
		if (left != nullptr)
			left->PreOrder(answer);
		if (right != nullptr)
			right->PreOrder(answer);
	}
	void PostOrder(vector<int>& answer)
	{
		if (left != nullptr)
			left->PostOrder(answer);
		if (right != nullptr)
			right->PostOrder(answer);
		answer.push_back(data);
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	priority_queue<Node> pq;
	for (int i = 0; i < nodeinfo.size(); ++i)
		pq.push(Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));

	Node root = pq.top(); pq.pop();
	while (pq.empty() == false)
	{
		Node* node = new Node(pq.top()); pq.pop();
		root.SetChild(node);
	}

	vector<int> preOrder, postOrder;
	root.PreOrder(preOrder);
	root.PostOrder(postOrder);
	delete root.left;
	delete root.right;
	root.left = nullptr;
	root.right = nullptr;
	return { preOrder, postOrder };
};

#include <iostream>

int main()
{
	for (vector<int> answer : solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} }))
	{
		for (int data : answer)
			cout << data << " ";
		cout << endl;
	}

	return 0;
}