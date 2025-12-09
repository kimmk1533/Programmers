#include <string>
#include <vector>
using namespace std;

void func(vector<vector<int>>& answer, int s, int e, int n, int m)
{
	if (n == 1)
	{
		answer.push_back({ s, e });
		return;
	}

	func(answer, s, m, n - 1, e);
	func(answer, s, e, 1, m);
	func(answer, m, e, n - 1, s);
}

vector<vector<int>> solution(int n)
{
	vector<vector<int>> answer;

	func(answer, 1, 3, n, 2);

	return answer;
}

#include <iostream>

ostream& operator<<(ostream& os, vector<int> v)
{
	os << "(";
	for (int i = 0; i < v.size() - 1; ++i)
		os << v[i] << ", ";
	os << v[v.size() - 1] << ")";

	return os;
}

int main()
{
	for (auto arr : solution(3))
		cout << arr << endl;

	return 0;
}