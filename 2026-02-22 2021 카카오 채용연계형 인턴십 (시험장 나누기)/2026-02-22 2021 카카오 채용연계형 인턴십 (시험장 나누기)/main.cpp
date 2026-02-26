#include <vector>

using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links)
{
	int answer = 0;
	return answer;
}

#include <iostream>

int main()
{
	cout << solution(3, { 12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1 }, { {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {8, 5}, {2, 10}, {3, 0}, {6, 1}, {11, -1}, {7, 4}, {-1, -1}, {-1, -1} }) << endl;
	cout << solution(1, { 6, 9, 7, 5 }, { {-1, -1}, {-1, -1}, {-1, 0}, {2, 1} }) << endl;
	cout << solution(2, { 6, 9, 7, 5 }, { {-1, -1}, {-1, -1}, {-1, 0}, {2, 1} }) << endl;
	cout << solution(4, { 6, 9, 7, 5 }, { {-1, -1}, {-1, -1}, {-1, 0}, {2, 1} }) << endl;

	return 0;
}