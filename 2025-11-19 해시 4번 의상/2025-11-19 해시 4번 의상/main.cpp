#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
	unordered_map<string, int> wardrobe;

	// 종류별 갯수 세기
	for (vector<string> cloth : clothes)
		++wardrobe[cloth[1]];

	int answer = 1;
	// 종류마다 한 벌 고르는 경우 + 안고르는 경우
	for (pair<string, int> p : wardrobe)
		answer *= p.second + 1;

	// 모든 종류 안고르는 경우 1 빼기
	return answer - 1;
}

#include <iostream>

int main()
{
	cout << solution(
		{
			{ "yellow_hat", "headgear" },
			{ "blue_sunglasses", "eyewear" },
			{ "green_turban", "headgear" },
		}
		) << "\n";
	cout << solution({
		{ "crow_mask", "face" },
		{ "blue_sunglasses", "face" },
		{ "smoky_makeup", "face" },
		}
		) << "\n";
	cout << solution({
		{ "round_glasses", "face" },
		{ "black_sunglasses", "face" },
		{ "blue_tshirt", "upper" },
		{ "jean", "lower" },
		{ "long_coat", "outer" },
		}) << "\n";

	return 0;
}