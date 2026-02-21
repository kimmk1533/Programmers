#include <vector>
using namespace std;

vector<vector<int>> dp(100001, { 2000, -1 });

void init_add(int number)
{
	if (number > 20)
		dp[number] = { 1, 0 };
	else
		dp[number] = { 1, 1 };
}

vector<int> solution(int target)
{
	for (int number = 1; number <= 20; ++number)
	{
		init_add(number);
		init_add(number * 2);
		init_add(number * 3);
	}
	dp[50] = { 1, 1 };

	for (int nextScore = 23; nextScore <= target; ++nextScore)
	{
		for (int currScore = 1; currScore <= 60 && currScore < nextScore; ++currScore)
		{
			int countSum = dp[currScore][0] + dp[nextScore - currScore][0];
			int singleSum = dp[currScore][1] + dp[nextScore - currScore][1];

			if (countSum < dp[nextScore][0] ||
				(countSum == dp[nextScore][0] && singleSum > dp[nextScore][1]))
				dp[nextScore] = { countSum, singleSum };
		}
	}

	return dp[target];
}

#include <iostream>

int main()
{
	for (int answer : solution(21))
		cout << answer << " ";
	cout << endl;

	for (int answer : solution(58))
		cout << answer << " ";
	cout << endl;

	for (int answer : solution(97))
		cout << answer << " ";
	cout << endl;

	return 0;
}