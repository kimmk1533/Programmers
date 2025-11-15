#include <string>
#include <set>
using namespace std;

const int MAX = 10000000;
bool isPrime[MAX];

void Eratosthenes()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < MAX; ++i)
	{
		if (isPrime[i] == false)
			continue;

		for (int j = 2; i * j < MAX; ++j)
		{
			isPrime[i * j] = false;
		}
	}
}

set<int> primeVec;

void dfs(string checkNum, string numbers)
{
	if (checkNum[0] == '0')
		return;

	if (isPrime[stoi(checkNum)])
		primeVec.insert(stoi(checkNum));

	for (int i = 0; i < numbers.size(); ++i)
	{
		string newCheckNum = checkNum + numbers[i];
		string newNumbers(numbers);

		dfs(newCheckNum, newNumbers.erase(i, 1));
	}
}

int solution(string numbers)
{
	Eratosthenes();

	for (int i = 0; i < numbers.size(); ++i)
	{
		string newCheckNum = numbers.substr(i, 1);
		string newNumbers(numbers);

		dfs(newCheckNum, newNumbers.erase(i, 1));
	}

	return primeVec.size();
}

#include <iostream>

int main()
{
	cout << solution("17") << "\n";
	primeVec.clear();
	cout << solution("011") << "\n";

	return 0;
}