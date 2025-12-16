#include <string>
#include <vector>
using namespace std;

// 최대 공약수
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// 최소 공배수
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int solution(vector<int> arr)
{
	int answer = arr[0];
	for (int i = 1; i < arr.size(); ++i)
		answer = lcm(answer, arr[i]);

	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 2, 6, 8, 14 }) << endl;
	cout << solution({ 1, 2, 3 }) << endl;

	return 0;
}