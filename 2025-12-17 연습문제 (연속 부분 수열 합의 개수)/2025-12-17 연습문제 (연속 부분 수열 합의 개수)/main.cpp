#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements)
{
	set<int> s;

	for (int size = 1; size <= elements.size(); ++size)
	{
		for (int startIndex = 0; startIndex < elements.size(); ++startIndex)
		{
			int sum = 0;
			for (int sumIndex = 0; sumIndex < size; ++sumIndex)
			{
				sum += elements[(startIndex + sumIndex) % elements.size()];
			}
			s.insert(sum);
		}
	}

	return s.size();
}

#include <iostream>

int main()
{
	cout << solution({ 7, 9, 1, 1, 4 });

	return 0;
}