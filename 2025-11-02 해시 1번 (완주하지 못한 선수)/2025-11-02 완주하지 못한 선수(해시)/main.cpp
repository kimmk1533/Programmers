/*

문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때,
완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

입출력 예
participant
["leo", "kiki", "eden"]
["marina", "josipa", "nikola", "vinko", "filipa"]
["mislav", "stanko", "mislav", "ana"]

completion
["eden", "kiki"]
["josipa", "filipa", "marina", "nikola"]
["stanko", "ana", "mislav"]

return
"leo"
"vinko"
"mislav"

*/

#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	map<string, int> participantCount;
	map<string, int> completionCount;

	int size = completion.size();
	for (int i = 0; i < size; ++i)
	{
		++completionCount[completion[i]];
		++participantCount[participant[i]];
	}
	++participantCount[participant[size]];

	string answer = "";

	for (int i = 0; i < size; ++i)
	{
		string name = completion[i];

		int& cCount = completionCount[name];
		int& pCount = participantCount[name];

		if (cCount != pCount)
		{
			answer = name;
			break;
		}

		--cCount;
		--pCount;
	}

	if (answer == "")
	{
		for (int i = 0; i < participant.size(); ++i)
		{
			string name = participant[i];

			if (participantCount[name] != 0)
			{
				answer = name;
				break;
			}
		}
	}

	return answer;
}

#include <iostream>

int main()
{
	vector<string> participant1({ "leo", "kiki", "eden" });
	vector<string> completion1({ "eden", "kiki" });
	cout << "예제1: " << solution(participant1, completion1) << endl;

	vector<string> participant2({ "marina", "josipa", "nikola", "vinko", "filipa" });
	vector<string> completion2({ "josipa", "filipa", "marina", "nikola" });
	cout << "예제2: " << solution(participant2, completion2) << endl;

	vector<string> participant3({ "mislav", "stanko", "mislav", "ana" });
	vector<string> completion3({ "stanko", "ana", "mislav" });
	cout << "예제3: " << solution(participant3, completion3) << endl;

	return 0;
}