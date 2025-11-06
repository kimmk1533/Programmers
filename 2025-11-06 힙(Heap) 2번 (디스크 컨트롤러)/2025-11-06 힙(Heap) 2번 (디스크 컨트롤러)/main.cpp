#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

struct cmp1
{
	bool operator()(pii& lhs, pii& rhs)
	{
		return (lhs.second == rhs.second) ? lhs.first > rhs.first : lhs.second > rhs.second;
	}
};
struct cmp2
{
	bool operator()(pii& lhs, pii& rhs)
	{
		return lhs.first > rhs.first;
	}
};

int solution(vector<vector<int>> jobs)
{
	int answer = 0;
	int size = jobs.size();

	priority_queue <pii, vector<pii>, cmp1> waitQ;
	priority_queue <pii, vector<pii>, cmp2> timeQ;

	for (int i = 0; i < size; ++i)
	{
		timeQ.push(make_pair(jobs[i][0], jobs[i][1]));
	}

	pii job = timeQ.top(); timeQ.pop();
	waitQ.push(job);
	int currTime = job.first;
	while (!waitQ.empty() || !timeQ.empty())
	{
		while (!timeQ.empty() &&
			timeQ.top().first <= currTime)
		{
			job = timeQ.top(); timeQ.pop();
			waitQ.push(job);
		}

		if (waitQ.empty())
		{
			job = timeQ.top(); timeQ.pop();
			currTime += job.first - currTime;
			waitQ.push(job);
		}

		job = waitQ.top(); waitQ.pop();
		currTime += job.second;

		answer += (currTime - job.first);
	}

	return answer / size;
}

#include <iostream>

int main()
{
	cout << solution({
		{ 0, 3 },
		{ 5, 20 },
		{ 7, 4 },
		});

	return 0;
}