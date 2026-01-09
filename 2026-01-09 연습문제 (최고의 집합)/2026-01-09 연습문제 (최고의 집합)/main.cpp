#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s)
{
	if (n > s)
		return { -1 };

	const int m = s % n;
	vector<int> answer(n - m, s / n);
	answer.insert(answer.end(), m, s / n + 1);

	return answer;
}

#include <iostream>

int main()
{
	for (auto answer : solution(2, 9))
		cout << answer << " ";
	cout << endl;

	for (auto answer : solution(2, 1))
		cout << answer << " ";
	cout << endl;

	for (auto answer : solution(2, 8))
		cout << answer << " ";
	cout << endl;

	return 0;
}