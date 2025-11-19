#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
	sort(people.begin(), people.end(), less<int>());

	int answer = 0;
	int left = 0, right = people.size() -1;
	while (left <= right)
	{
		// 몸무게 가장 큰 사람 태우기
		int weight = people[right--];

		// 몸무게 낮은 사람 태우기
		if (left <= right &&
			weight + people[left] <= limit)
			weight += people[left++];

		++answer;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 70, 50, 80, 50 }, 100) << "\n";
	cout << solution({ 70, 80, 50 }, 100) << "\n";
	cout << solution({ 40, 50, 60, 50 }, 100) << "\n";
	cout << solution({ 40, 40, 40, 40, 40, 200, 40, 240 }, 240) << "\n";
	cout << solution({ 100, 100, 50, 40 }, 140) << "\n";

	return 0;
}