#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	priority_queue<int, vector<int>, greater<int>> A_PQ(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> B_PQ(B.begin(), B.end());

	int answer = 0;
	while (A_PQ.empty() == false)
	{
		int a = A_PQ.top(); A_PQ.pop();
		while (B_PQ.empty() == false)
		{
			int b = B_PQ.top(); B_PQ.pop();
			if (a < b)
			{
				++answer;
				break;
			}
		}
	}
	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 5, 1, 3, 7, }, { 2, 2, 6, 8 }) << endl;
	cout << solution({ 2, 2, 2, 2, }, { 1, 1, 1, 1 }) << endl;
	cout << solution({ 1, 3, 9, 9, }, { 2, 2, 8, 10 }) << endl;

	return 0;
}