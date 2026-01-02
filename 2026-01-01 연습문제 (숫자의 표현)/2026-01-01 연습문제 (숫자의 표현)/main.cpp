#include <string>
#include <vector>
using namespace std;

int solution(int n)
{
	int answer = 0;
	int num = n;
	int sum = 0;
	int pivot = n;
	
	while (num > 0)
	{
		sum += num;

		if (sum >= n)
		{
			if (sum == n)
				++answer;

			num = pivot;
			sum = 0;
			pivot = num - 1;
		}

		--num;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(15);

	return 0;
}