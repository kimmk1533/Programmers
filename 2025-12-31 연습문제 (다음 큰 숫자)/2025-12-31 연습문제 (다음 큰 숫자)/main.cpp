#include <string>
#include <vector>
using namespace std;

int bitCount(int n)
{
	int cnt = 0;
	int test = 1;

	while (test <= n)
	{
		if (n & test)
			++cnt;
		test <<= 1;
	}

	return cnt;
}

int solution(int n)
{
	int nBit = bitCount(n);
	int bit = 0;

	while (nBit != bit)
	{
		bit = bitCount(++n);
	}

	return n;
}

#include <iostream>

int main()
{
	cout << solution(15);

	return 0;
}