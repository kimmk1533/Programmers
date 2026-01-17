#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works)
{
	priority_queue<int> pq(works.begin(), works.end());

	for (int i = 0; i < n; ++i)
	{
		int work = pq.top(); pq.pop();
		if (work - 1 != 0)
			pq.push(work - 1);
		if (pq.empty() == true)
			break;
	}
	long long answer = 0;
	while (pq.empty() == false)
	{
		answer += pq.top() * pq.top();
		pq.pop();
	}
	return answer;
}

#include <iostream>

int main()
{
	cout << solution(3, { 1, 1 });

	return 0;
}