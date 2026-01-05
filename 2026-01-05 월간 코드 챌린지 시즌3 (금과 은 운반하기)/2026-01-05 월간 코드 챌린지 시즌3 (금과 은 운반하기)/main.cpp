#include <string>
#include <vector>
using namespace std;

bool canCarry(const int& n, long long& time, int& a, int& b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t)
{
	long long carriedG = 0, carriedS = 0, carriedTotal = 0;

	for (int i = 0; i < n; ++i)
	{
		// (이동 횟수(현재 확인 중인 시간 / 편도 시간) + 편도 횟수) / 2(돌아오는 횟수 제거) * (한 번에 옮길 수 있는 무게)
		long long maxWeight = (time / t[i] + 1) / 2 * w[i];

		carriedG += min((long long)g[i], maxWeight);
		carriedS += min((long long)s[i], maxWeight);
		carriedTotal += min((long long)(g[i] + s[i]), maxWeight);
	}

	return carriedG >= a && carriedS >= b && carriedTotal >= (a + b);
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
	const int n = g.size();

	long long left = 1, right = (1e9 * 2 * 1e5 * 2);
	long long mid = -1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (left == right)
			break;

		if (canCarry(n, mid, a, b, g, s, w, t) == true)
			right = mid;
		else
			left = mid + 1;
	}

	return mid;
}

#include <iostream>

int main()
{
	cout << solution(10, 10, { 100 }, { 100, }, { 7, }, { 10, }) << endl;
	cout << solution(90, 500, { 70, 70, 0 }, { 0, 0, 500 }, { 100, 100, 2 }, { 4, 8, 1 }) << endl;

	return 0;
}