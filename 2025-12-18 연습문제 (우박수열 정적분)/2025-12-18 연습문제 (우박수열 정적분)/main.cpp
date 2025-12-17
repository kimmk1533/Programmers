#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
	vector<double> extent;
	while (k != 1)
	{
		int next = (k % 2 == 0) ? k / 2 : k * 3 + 1;
		extent.push_back((k + next) / 2.);
		k = next;
	}

	int n = extent.size();
	vector<double> answer;
	for (vector<int> range : ranges)
	{
		int a = range[0];
		int b = n + range[1];

		if (a > b)
		{
			answer.push_back(-1.);
			continue;
		}

		double sum = 0.;
		for (int i = a; i < b; ++i)
			sum += extent[i];
		answer.push_back(sum);
	}

	return answer;
}

#include <iostream>

int main()
{
	for (double result : solution(5, { {0, 0 }, { 0, -1 }, { 2, -3 }, { 3, -3 } }))
		cout << result << " ";
	cout << endl;

	return 0;
}
