#include <string>
#include <vector>
using namespace std;

int dpFirst[1000001];
int dpLast[1000001];

// 참고: https://school.programmers.co.kr/questions/31576
int solution(vector<int> money)
{
	for (int i = 0; i < money.size() - 1; ++i)
	{
		dpFirst[i + 2] = max(dpFirst[i + 1], dpFirst[i] + money[i]);
		dpLast[i + 2] = max(dpLast[i + 1], dpLast[i] + money[i + 1]);
	}

	return max(dpFirst[money.size()], dpLast[money.size()]);
}

#include <iostream>

int main()
{
	cout << solution({ 1, 2, 3, 1 }) << " " << 4 << endl;
	cout << solution({ 1, 1, 4, 1, 4 }) << " " << 8 << endl;
	cout << solution({ 1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000 }) << " " << 3000 << endl;
	cout << solution({ 1000, 1, 0, 1, 2, 1000, 0 }) << " " << 2001 << endl;
	cout << solution({ 1000, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 1000 }) << " " << 2000 << endl;
	cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) << " " << 30 << endl;
	cout << solution({ 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 1, 1 }) << " " << 201 << endl;
	cout << solution({ 11, 0, 2, 5, 100, 100, 85, 1 }) << " " << 198 << endl;
	cout << solution({ 1, 2, 3 }) << " " << 3 << endl;
	cout << solution({ 91, 90, 5, 7, 5, 7 }) << " " << 104 << endl;
	cout << solution({ 90, 0, 0, 95, 1, 1 }) << " " << 185 << endl;

	return 0;
}