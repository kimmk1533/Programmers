#include <vector>
using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer;

	for (int i = 0; i < prices.size(); ++i)
	{
		int price = 0;
		for (int j = i + 1; j < prices.size(); ++j)
		{
			++price;

			if (prices[i] > prices[j])
				break;
		}
		answer.push_back(price);
	}

	return answer;
}

#include <iostream>

int main()
{
	for (int answer : solution({ 1, 2, 3, 2, 3 }))
	{
		cout << answer << " ";
	}

	return 0;
}