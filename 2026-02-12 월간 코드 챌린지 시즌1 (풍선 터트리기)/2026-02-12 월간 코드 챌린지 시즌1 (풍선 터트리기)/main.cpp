#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a)
{
	int answer = 0, minValue = a[a.size() - 1];
	int minIndex = distance(a.begin(), min_element(a.begin(), a.end()));

	vector<int> minVec(a.size());
	for (int i = 0; i <= minIndex; ++i)
		minVec[i] = a[minIndex];
	for (int i = a.size() - 1; i > minIndex; --i)
		minVec[i] = minValue = min(a[i], minValue);

	minValue = a[0];
	for (int i = 0; i < a.size(); ++i)
	{
		int left = minValue = min(minValue, a[i]);
		int right = minVec[i];

		if (!(left < a[i] && right < a[i]))
			++answer;
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 9, -1, -5 }) << endl;
	cout << solution({ -16, 27, 65, -2, 58, -92, -71, -68, -61, -33 }) << endl;

	return 0;
}