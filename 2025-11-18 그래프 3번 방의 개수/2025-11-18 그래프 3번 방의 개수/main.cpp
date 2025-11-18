#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// pair를 해싱하기 위한 구조체 정의
struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const& v) const
	{
		auto h1 = std::hash<T1> {}(v.first);
		auto h2 = std::hash<T2> {}(v.second);
		return h1 ^ h2;
	}
};

typedef pair<int, int> point;
typedef unordered_set<point, pair_hash> point_set;
typedef unordered_map<point, point_set, pair_hash> point_map;

const int dx[8] = { 0,  1,  1,  1,  0, -1, -1, -1 };
const int dy[8] = { 1,  1,  0, -1, -1, -1,  0,  1 };

int solution(vector<int> arrows)
{
	point_set nodes;
	point_map edges;

	point curr = make_pair(0, 0);
	int answer = 0;

	nodes.insert(curr);

	int nodeCnt = 1;
	int edgeCnt = 0;

	for (int arrow : arrows)
	{
		pair<point_set::iterator, bool> nodeResult;
		pair<point_set::iterator, bool> edgeResult;

		// .5 노드 구현을 위해 2번씩 움직임
		for (int i = 0; i < 2; ++i)
		{
			point prev = curr;

			curr.first += dx[arrow];
			curr.second += dy[arrow];

			// 다음 노드로 이동
			nodeResult = nodes.insert(curr);
			edgeResult = edges[prev].insert(curr);
			edges[curr].insert(prev);

			if (nodeResult.second)
				++nodeCnt;
			if (edgeResult.second)
				++edgeCnt;

			// 기존 노선에 닿음 & 새로운 선분이 생김
			if (nodeResult.second == false && edgeResult.second == true)
			{
				// 오일러 다면체 정리(면의 개수 = 선분의 개수 - 꼭짓점의 개수 + 1)
				answer += edgeCnt - nodeCnt + 1;
				nodeCnt = 1;
				edgeCnt = 0;
			}
		}
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution({ 2, 7, 2, 5, 0 });

	return 0;
}