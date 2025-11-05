#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int cnt = nums.size() >> 1;

	set<int> s(nums.begin(), nums.end());

	return min<int>(cnt, s.size());
}

#include <iostream>

int main()
{
	cout << solution({ 3, 1, 2, 3 });
}