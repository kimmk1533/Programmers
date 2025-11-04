#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int sum, int i)
{
	int answer = 0;

	if (i >= numbers.size() - 1)
	{
		if (sum + numbers[i] == target)
			++answer;
		if (sum - numbers[i] == target)
			++answer;

		return answer;
	}

	answer += dfs(numbers, target, sum + numbers[i], i + 1);
	answer += dfs(numbers, target, sum - numbers[i], i + 1);

	return answer;
}

int solution(vector<int> numbers, int target)
{
	int answer = dfs(numbers, target, 0, 0);

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(vector<int> { 4, 1, 2, 1 }, 4);
}