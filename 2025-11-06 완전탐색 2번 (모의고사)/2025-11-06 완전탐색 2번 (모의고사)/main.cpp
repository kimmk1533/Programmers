#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<vector<int>> supoja =
	{
		{ 1, 2, 3, 4, 5 },
		{ 2, 1, 2, 3, 2, 4, 2, 5 },
		{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 },
	};

	vector<int> score = { 0, 0, 0 };
	int maxScore = 0;

	vector<int> answer;

	for (int i = 0; i < answers.size(); ++i)
	{
		score[0] += (supoja[0][i % 5] == answers[i]) ? 1 : 0;
		score[1] += (supoja[1][i % 8] == answers[i]) ? 1 : 0;
		score[2] += (supoja[2][i % 10] == answers[i]) ? 1 : 0;

		maxScore = max<int>({ maxScore, score[0], score[1], score[2] });
	}

	for (int i = 0; i < 3; ++i)
	{
		if (score[i] == maxScore)
			answer.push_back(i + 1);
	}

	return answer;
}

#include <iostream>

int main()
{
	for (int answer : solution({ 1, 3, 2, 4, 2 }))
	{
		cout << answer << " ";
	}

	return 0;
}