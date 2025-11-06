#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
public:
	bool operator()(string& lhs, string& rhs)
	{
		return lhs + rhs < rhs + lhs;
	}
};

string solution(vector<int> numbers)
{
	string answer = "";

	priority_queue<string, vector<string>, cmp> strQ;

	for (int number : numbers)
		strQ.push(to_string(number));

	int size = strQ.size();
	for (int i = 0; i < size; ++i)
	{
		answer += strQ.top(); strQ.pop();
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 0, 0, 0, 0, 0, 0 });

	return 0;
}