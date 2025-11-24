#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<pair<int, int>> currTrucks;
	int currWeight = truck_weights[0];
	currTrucks.push({ currWeight, 1 });
	int currTime = 2;

	int index = 1;
	int answer = 1;

	while (currTrucks.empty() == false)
	{
		if (currTime - currTrucks.front().second >= bridge_length)
		{
			pair<int, int> truck = currTrucks.front(); currTrucks.pop();
			currWeight -= truck.first;
			answer = currTime;
		}

		if (index < truck_weights.size() &&
			currWeight + truck_weights[index] <= weight)
		{
			currWeight += truck_weights[index];
			currTrucks.push({ truck_weights[index++], currTime });
			++currTime;
		}
		else if (currTrucks.empty() == false)
		{
			currTime = currTrucks.front().second + bridge_length;
		}
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(2, 10, { 7, 4, 5, 6 }) << "\n";
	cout << solution(100, 100, { 10 }) << "\n";
	cout << solution(100, 100, { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }) << "\n";
	cout << solution(10, 100, { 50, 30, 10, 10, 30, 10, 40 }) << "\n";
	cout << solution(10, 100, { 50, 30, 20, 10, 10, 10, 10, 10, 10 }) << "\n";

	return 0;
}