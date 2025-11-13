#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int indent = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ')')
		{
			if (indent == 0)
				return false;

			--indent;
		}
		if (s[i] == '(')
			++indent;
	}
	return indent == 0;
}

int main()
{
	cout << solution("()()") << "\n";
	cout << solution("(())()") << "\n";
	cout << solution(")()(") << "\n";
	cout << solution("(()(") << "\n";
	cout << solution("(") << "\n";

	return 0;
}