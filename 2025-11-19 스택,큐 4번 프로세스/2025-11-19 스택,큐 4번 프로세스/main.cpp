#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
	queue<int> q;
	priority_queue<int> pq(priorities.begin(), priorities.end());
	for (int priority : priorities)
	{
		q.push(priority);
	}

	int answer = 1;

	while (q.empty() == false)
	{
		int process = q.front(); q.pop();

		if (process == pq.top())
		{
			if (location == 0)
				break;

			++answer;
			pq.pop();
		}
		else
		{
			q.push(process);

			if (location == 0)
				location = q.size();
		}

		--location;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 2, 1, 3, 2 }, 2) << "\n";
	cout << solution({ 1, 1, 9, 1, 1, 1 }, 0) << "\n";

	return 0;
}