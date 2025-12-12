#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n)
{
	vector<vector<int>> triangle(n, vector<int>());

	int index = 0;
	int num = 1;
	int level = 0;

	while (level != n)
	{
		// 1. 왼쪽 아래로 내려가기
		for (int i = 0; i < n - level; ++i)
			triangle[i + index * 2].insert(triangle[i + index * 2].begin() + index, num++);

		if (++level == n)
			break;

		// 2. 맨 아래줄 채우기
		for (int i = 0; i < n - level; ++i)
			triangle[n - 1 - index].insert(triangle[n - 1 - index].end() - index, num++);

		if (++level == n)
			break;

		// 3. 오른쪽 위로 올라가기
		for (int i = 0; i < n - level; ++i)
			triangle[n - 1 - (i + index + 1)].insert(triangle[n - 1 - (i + index + 1)].end() - index, num++);

		if (++level == n)
			break;

		++index;
	}

	vector<int> answer;
	for (auto line : triangle)
	{
		answer.insert(answer.end(), line.begin(), line.end());
	}
	return answer;
}

#include <iostream>

int main()
{
	cout << "( ";
	for (int answer : solution(6))
	{
		cout << answer << " ";
	}
	cout << ")";

	return 0;
}