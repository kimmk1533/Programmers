#include <string>
#include <vector>
using namespace std;

bool check(string p)
{
	int cnt1 = 0, cnt2 = 0;
	for (char ch : p)
	{
		(ch == '(') ? ++cnt1 : ++cnt2;

		if (cnt2 > cnt1)
			return false;
	}
	return true;
}

string solution(string p)
{
	if (p == "")
		return "";
	if (check(p))
		return p;

	string u = "", v = "";
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < p.size(); ++i)
	{
		u += p[i];
		(p[i] == '(') ? ++cnt1 : ++cnt2;

		if (cnt1 == cnt2)
		{
			v = p.substr(i + 1, p.size() - i);
			break;
		}
	}

	if (check(u))
		return u + solution(v);

	string answer = "(";
	answer += solution(v);
	answer += ")";
	for (int i = 1; i < u.size() - 1; ++i)
	{
		answer += ((u[i] == '(') ? ')' : '(');
	}
	return answer;
}

#include <iostream>

int main()
{
	//cout << solution("(()())()") << " " << (solution("(()())()") == "(()())()") << endl;
	cout << solution(")(") << " " << (solution(")(") == "()") << endl;
	cout << solution("()))((()") << " " << (solution("()))((()") == "()(())()") << endl;

	return 0;
}