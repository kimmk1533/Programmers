#include <cmath>
using namespace std;

int dfs(const int n, const int m, const int s, const int cntM, const int cntS)
{
	// * 갯수가 넘치는 상황 배제
	if (cntM * 2 > cntS)
		return 0;
	if (n < 3)
		return 0;
	if (n == 3 && (cntM + 1) * 2 == cntS)
		return 1;

	int a = 0, b = 0;
	if (s > 0)
		a = dfs(n - 1, m, s - 1, cntM, cntS + 1);
	if (n % 3 == 0 && m > 0)
		b = dfs(n / 3, m - 1, s, cntM + 1, cntS);
	return a + b;
}

int solution(int n)
{
	int m = log(n) / log(3);
	return dfs(n - 2, m, m * 2 - 2, 0, 2);
}

#include <iostream>

int main()
{
	cout << solution(15) << endl;
	cout << solution(24) << endl;
	cout << solution(41) << endl;
	cout << solution(2147483647) << endl;

	return 0;
}