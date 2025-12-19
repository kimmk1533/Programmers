#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	map<char, char> skilltree;
	for (int i = skill.size() - 1; i > 0; --i)
	{
		char curr = skill[i];
		char parent = skill[i - 1];

		skilltree.insert({ curr, parent });
	}

	int answer = 0;
	for (string userSkillTree : skill_trees)
	{
		bool s[26] = { false, };
		bool flag = false;
		for (char skill : userSkillTree)
		{
			int index = skill - 'A';
			auto iter = skilltree.find(skill);

			// 선행 스킬 트리에 있으면
			if (iter != skilltree.end())
			{
				// 선행 스킬을 안배웠으면
				if (s[(*iter).second - 'A'] == false)
				{
					flag = true;
					break;
				}
			}

			s[index] = true;
		}

		if (flag == false)
			++answer;
	}
	return answer;
}

#include <iostream>

int main()
{
	cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });

	return 0;
}