#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator()(vector<int> a, vector<int> b)
	{
		return a[1] < b[1];
	}
};

int solution(vector<vector<int>> routes)
{
	sort(routes.begin(), routes.end(), cmp());

	int answer = 0;
	int point = routes[0][1];
	for (vector<int> route : routes)
	{
		if (point < route[0])
		{
			point = route[1];
			++answer;
		}
	}

	return answer + 1;
}

#include <iostream>

int main()
{
	cout << solution({ {-14, -5}, {-18, -13}, {-5, -3}, {-20, -15}, {-20, -10 } }) << endl;

	return 0;
}