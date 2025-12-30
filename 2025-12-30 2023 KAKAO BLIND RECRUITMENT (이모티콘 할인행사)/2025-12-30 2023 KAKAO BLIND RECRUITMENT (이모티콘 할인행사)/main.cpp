#include <string>
#include <vector>
using namespace std;

const int discount[4] { 10, 20, 30, 40 };
int plusCount = 0;
int price = 0;

pair<int, int> get_answer(vector<vector<int>>& users, vector<int>& emoticons, vector<int> discountRates)
{
	int plusCount = 0;
	int price = 0;

	for (vector<int> user : users)
	{
		int userPrice = 0;

		for (int i = 0; i < emoticons.size(); ++i)
		{
			// 일정 비율 이상 할인하지 않는 이모티콘은 구매X
			if (user[0] > discountRates[i])
				continue;

			userPrice += emoticons[i] * ((100.f - discountRates[i]) / 100.f);

			// 일정 금액 이상 구매 시 구매 취소 후 플러스 가입
			if (userPrice >= user[1])
			{
				userPrice = 0;
				++plusCount;
				break;
			}
		}

		price += userPrice;
	}

	return { plusCount, price };
}

void dfs(int level, vector<vector<int>>& users, vector<int>& emoticons, vector<int> discountRates)
{
	if (level >= emoticons.size())
	{
		pair<int, int> answer = get_answer(users, emoticons, discountRates);

		if (plusCount < answer.first ||
			(plusCount == answer.first &&
			price < answer.second))
		{
			plusCount = answer.first;
			price = answer.second;
		}

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		discountRates[level] = discount[i];
		dfs(level + 1, users, emoticons, discountRates);
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
	dfs(0, users, emoticons, vector<int>(emoticons.size(), 0));

	return { plusCount, price };
}

#include <iostream>

int main()
{
	vector<int> answer = solution({
		{ 40, 2900 },
		{ 23, 10000 },
		{ 11, 5200 },
		{ 5, 5900 },
		{ 40, 3100 },
		{ 27, 9200 },
		{ 32, 6900 },
		}, { 1300, 1500, 1600, 4900 });

	cout << answer[0] << ", " << answer[1] << endl;

	return 0;
}