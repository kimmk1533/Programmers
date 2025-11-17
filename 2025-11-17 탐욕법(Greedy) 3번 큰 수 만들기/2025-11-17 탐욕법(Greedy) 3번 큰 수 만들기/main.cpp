#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
	int size = number.size() - 1;
	for (int i = 0; i < size; ++i)
	{
		if (k == 0)
			break;

		if (i < 0)
			continue;

		// 뒷자리 숫자가 더 크면
		if (number[i] < number[i + 1])
		{
			// 지워야될 갯수 감소
			--k;
			// 현재 자리 숫자 삭제
			number.erase(i, 1);
			// 이전 숫자부터 다시 검사
			i -= 2;
			continue;
		}
	}

	// 반복문을 완료하고도 k가 남아있다면 내림차순 되어있다는 뜻이므로 남은 k 갯수만큼 뒤에 있는 숫자 제거 하면 됨
	if (k > 0)
		number.erase(number.size() - k, k);

	return number;
}

#include <iostream>

int main()
{
	cout << solution("1924", 2) << "\n";
	cout << solution("1231234", 3) << "\n";
	cout << solution("4177252841", 4) << "\n";
	cout << solution("123456789", 8) << "\n";
	cout << solution("987654321", 8) << "\n";

	return 0;
}