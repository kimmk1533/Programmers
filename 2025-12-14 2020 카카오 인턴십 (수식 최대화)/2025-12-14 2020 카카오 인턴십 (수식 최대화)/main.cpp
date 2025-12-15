#include <string>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

long long func(string expression, vector<char> operPriority)
{
	// 계산식에 존재하는 연산자 찾기
	set<char> operSet;
	for (auto iter = expression.begin() + 1; iter != expression.end(); ++iter)
	{
		if (*iter == '+' || *iter == '-' || *iter == '*')
			operSet.insert(*iter);
	}

	// 계산식에 연산자가 없으면 종료
	if (operSet.size() == 0)
		return llabs(stoll(expression));

	// 현재 확인할 연산자
	char oper = ' ';
	for (char op : operPriority)
		if (operSet.find(op) != operSet.end())
		{
			oper = op;
			break;
		}

	string::const_iterator iter1;
	string::const_iterator iter2;

	string num1 = "";
	string num2 = "";

	int index = 0;
	int size = 0;
	bool findOper = false;

	long long answer = 0;

	for (auto iter = expression.begin(); iter != expression.end(); ++iter)
	{
		++size;

		// 연산자
		auto findIter = operSet.find(*iter);
		if (findIter != operSet.end())
		{
			if (findOper == true)
			{
				num2 = expression.substr(index, size - 1);
				iter2 = expression.begin() + index + size - 1;
				break;
			}

			if (*findIter == oper)
			{
				num1 = expression.substr(index, size - 1);

				iter1 = expression.begin() + index;
				index = index + size;
				size = 0;
				findOper = true;
			}
			else
			{
				index += size;
				size = 0;
			}
		}

		// 마지막까지 왔으면 여기가 num2
		if (iter == (expression.end() - 1))
		{
			num2 = expression.substr(index, size);
			iter2 = expression.begin() + index + size;
		}
	}

	if (num1.size() > 1 &&
		num1[0] == '0')
		num1[0] = '-';
	if (num2.size() > 1 &&
		num2[0] == '0')
		num2[0] = '-';

	string  replacedStr;

	if (oper == '+')
		replacedStr = to_string(stoll(num1) + stoll(num2));
	else if (oper == '-')
		replacedStr = to_string(stoll(num1) - stoll(num2));
	else if (oper == '*')
		replacedStr = to_string(stoll(num1) * stoll(num2));\

		if (replacedStr[0] == '-')
			replacedStr[0] = '0';

	expression.replace(iter1, iter2, replacedStr);

	answer = max(answer, func(expression, operPriority));

	return llabs(answer);
}

long long solution(string expression)
{
	long long answer = 0;

	answer = max(answer, func(expression, { '+', '-', '*' }));
	answer = max(answer, func(expression, { '+', '*', '-' }));
	answer = max(answer, func(expression, { '-', '+', '*' }));
	answer = max(answer, func(expression, { '-', '*', '+' }));
	answer = max(answer, func(expression, { '*', '+', '-' }));
	answer = max(answer, func(expression, { '*', '-', '+' }));

	return answer;
}

#include <iostream>

int main()
{
	cout << solution("100-200*300-500+20") << endl;
	cout << solution("50*6-3*2") << endl;

	return 0;
}