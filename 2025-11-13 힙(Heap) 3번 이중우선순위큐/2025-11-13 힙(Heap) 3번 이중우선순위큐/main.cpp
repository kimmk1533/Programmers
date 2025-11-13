#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations)
{
	priority_queue<int> pq;

	for (string operation : operations)
	{
		// 삽입
		if (operation[0] == 'I')
		{
			int data = stoi(operation.substr(2));

			pq.push(data);
		}
		// 최댓값 제거
		else if (operation == "D 1")
		{
			if (pq.empty())
				continue;

			pq.pop();
		}
		// 최솟값 제거
		else if (operation == "D -1")
		{
			if (pq.empty())
				continue;

			priority_queue<int> tempPQ;
			int size = pq.size() - 1;
			for (int i = 0; i < size; ++i)
			{
				tempPQ.push(pq.top());
				pq.pop();
			}
			pq = tempPQ;
		}
	}

	vector<int> answer;

	if (pq.empty())
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (pq.size() == 1)
	{
		answer.push_back(pq.top());
		answer.push_back(pq.top());
	}
	else
	{
		answer.push_back(pq.top()); pq.pop();
		int size = pq.size() - 1;
		for (int i = 0; i < size; ++i)
			pq.pop();
		answer.push_back(pq.top()); pq.pop();
	}

	return answer;
}

#include <iostream>

int main()
{
	vector<int> result = solution(
		{
			"I -45",
			"I 653",
			"D 1",
			"I -642",
			"I 45",
			"I 97",
			"D 1",
			"D -1",
			"I 333",
		}
		);

	/*vector<int> result = solution(
		{
			"I 16",
			"I -5643",
			"D -1",
			"D 1",
			"D 1",
			"I 123",
			"D -1",
		}
		);*/

	for (int d : result)
	{
		cout << d << " ";
	}

	return 0;
}