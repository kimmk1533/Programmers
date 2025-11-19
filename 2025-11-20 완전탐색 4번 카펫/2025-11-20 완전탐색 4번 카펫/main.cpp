#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow)
{
	int width = 2, height = 2;

	while (true)
	{
		height = 2;

		while (height <= width)
		{
			int yellow_carpet = (width - 2) * (height - 2);
			int brown_carpet = width * height - yellow_carpet;

			if (yellow == yellow_carpet &&
				brown == brown_carpet)
				return { width, height };

			++height;
		}

		++width;
	}
}

#include <iostream>

int main()
{
	vector<int> answer = solution(24, 24);
	cout << answer[0] << ", " << answer[1] << "\n";

	return 0;
}