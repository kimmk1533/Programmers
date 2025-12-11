#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

std::string toNBase(int num, int n) {
	if (num == 0) return "0";
	std::string result = "";
	char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // 16진수까지 대응
	while (num > 0) {
		result += map[num % n]; // 나머지로 문자 추가
		num /= n; // 몫으로 업데이트
	}
	std::reverse(result.begin(), result.end()); // 문자열 뒤집기
	return result;
}

string solution(int n, int t, int m, int p)
{
	string answer = "";
	queue<string> q;
	q.push("0");
	int index = 0;
	int cnt = 0;

	p %= m;

	while (answer.size() != t)
	{
		++index;
		string curr = q.front(); q.pop();

		for (char ch : curr)
		{
			if (++cnt % m == p)
				answer += ch;

			if (answer.size() == t)
				break;
		}

		q.push(toNBase(index, n));
	}

	return answer;
}

#include <iostream>

int main()
{
	string temp = solution(2, 4, 2, 1);
	cout << temp << " " << "0111 = " << ((temp == "0111") ? "true" : "false") << endl;
	temp = solution(16, 16, 2, 1);
	cout << temp << " " << "02468ACE11111111 = " << ((temp == "02468ACE11111111") ? "true" : "false") << endl;
	temp = solution(16, 16, 2, 2);
	cout << temp << " " << "13579BDF01234567 = " << ((temp == "13579BDF01234567") ? "true" : "false") << endl;

	return 0;
}