using namespace std;

// n: 전체 괄호 갯수, level: 현재 괄호 갯수, open: 열린 괄호 갯수, close: 닫힌 괄호 갯수
int dfs(const int& n, const int& level, const int open, const int close)
{
	if (close > open)
		return 0;
	if (level >= n)
	{
		if (level == n &&
			open == close)
			return 1;
		return 0;
	}

	return dfs(n, level + 1, open + 1, close) + dfs(n, level + 1, open, close + 1);
}

int solution(int n)
{
	return dfs(n * 2, 0, 0, 0);
}

#include <iostream>

int main()
{
	cout << solution(2) << endl;
	cout << solution(3) << endl;

	return 0;
}