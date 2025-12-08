#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] { 0, 1, 0, -1 };
const int dy[4] { -1, 0, 1, 0 };

struct Point
{
public:
	int x;
	int y;

	Point operator+ (const Point& other) const { return { x + other.x, y + other.y }; }
	Point operator- (const Point& other) const { return { x - other.x, y - other.y }; }
	Point operator- () const { return { -x, -y }; }

	Point& operator+= (const Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Point& operator-= (const Point& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	bool operator> (const Point& other) const
	{
		if (y == other.y)
			return x > other.x;

		return y > other.y;
	}
	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}
};
class Brick
{
private:
	priority_queue<Point, vector<Point>, greater<Point>> m_Points;
	Point m_Max;

	friend class BrickLogger;

	Brick Rotate90()
	{
		Brick rotatedBrick;

		priority_queue<Point, vector<Point>, greater<Point>> tempQ = m_Points;
		while (tempQ.empty() == false)
		{
			Point curr = tempQ.top(); tempQ.pop();

			rotatedBrick.AddPoint({ curr.y, -curr.x });
		}

		rotatedBrick.Sort();

		return rotatedBrick;
	}
	Brick Rotate180()
	{
		Brick rotatedBrick;

		priority_queue<Point, vector<Point>, greater<Point>> tempQ = m_Points;
		while (tempQ.empty() == false)
		{
			Point curr = tempQ.top(); tempQ.pop();

			rotatedBrick.AddPoint({ -curr.x, -curr.y });
		}

		rotatedBrick.Sort();

		return rotatedBrick;
	}
	Brick Rotate270()
	{
		Brick rotatedBrick;

		priority_queue<Point, vector<Point>, greater<Point>> tempQ = m_Points;
		while (tempQ.empty() == false)
		{
			Point curr = tempQ.top(); tempQ.pop();

			rotatedBrick.AddPoint({ -curr.y, curr.x });
		}

		rotatedBrick.Sort();

		return rotatedBrick;
	}
public:
	void AddPoint(int x, int y)
	{
		AddPoint({ x , y });
	}
	void AddPoint(Point point)
	{
		m_Points.push(point);

		m_Max.x = max(m_Max.x, point.x);
		m_Max.y = max(m_Max.y, point.y);
	}
	void Sort()
	{
		vector<Point> tempPoints;
		Point offset { 50, 50 };

		while (m_Points.empty() == false)
		{
			Point temp = m_Points.top(); m_Points.pop();

			offset.x = min(offset.x, temp.x);
			offset.y = min(offset.y, temp.y);

			tempPoints.push_back(temp);
		}

		for (Point point : tempPoints)
		{
			m_Points.push(point - offset);
		}

		m_Max -= offset;
	}
	vector<Brick> GetRotatedBrick()
	{
		vector<Brick> brickList;

		brickList.push_back(*this);
		brickList.push_back(Rotate90());
		brickList.push_back(Rotate180());
		brickList.push_back(Rotate270());

		return brickList;
	}
	int GetCount() { return m_Points.size(); }

public:
	Brick()
	{
		m_Points = priority_queue<Point, vector<Point>, greater<Point>>();

		m_Max = { 0, 0 };
	}
	Brick(const Brick& other)
	{
		this->m_Points = other.m_Points;

		m_Max = other.m_Max;
	}

	bool operator==(const Brick& other) const
	{
		if (m_Points.size() != other.m_Points.size())
			return false;

		auto a = m_Points;
		auto b = other.m_Points;

		while (!a.empty())
		{
			if (!(a.top() == b.top()))
				return false;

			a.pop();
			b.pop();
		}

		return true;
	}
};

Brick bfs(vector<vector<int>>& map, int sx, int sy, int findValue)
{
	Brick brick;
	Point curr = { sx, sy };
	map[curr.y][curr.x] = 2;
	brick.AddPoint(curr);

	queue<Point> q;
	q.push(curr);

	while (q.empty() == false)
	{
		curr = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			Point next = { curr.x + dx[i], curr.y + dy[i] };
			if (next.x < 0 || next.y < 0)
				continue;
			if (next.x >= map.size() || next.y >= map.size())
				continue;
			if (map[next.y][next.x] != findValue)
				continue;
			map[next.y][next.x] = 2;
			brick.AddPoint(next);
			q.push(next);
		}
	}

	return brick;
}
vector<Brick> find(vector<vector<int>>& map, bool findBlank)
{
	vector<Brick> brickList;

	int findValue = findBlank ? 0 : 1;
	for (int y = 0; y < map.size(); ++y)
	{
		for (int x = 0; x < map.size(); ++x)
		{
			if (map[y][x] != findValue)
				continue;

			Brick brick = bfs(map, x, y, findValue);
			brick.Sort();
			brickList.push_back(brick);
		}
	}

	return brickList;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	// 벽돌 찾기
	vector<Brick> brickList = find(table, false);

	// 빈칸 찾기
	vector<Brick> blankList = find(game_board, true);

	int answer = 0;
	for (int i = 0; i < blankList.size(); ++i)
	{
		Brick blank = blankList[i];

		for (int j = 0; j < brickList.size(); ++j)
		{
			Brick brick = brickList[j];
			bool flag = false;

			for (Brick rotatedBrick : brick.GetRotatedBrick())
			{
				if (blank == rotatedBrick)
				{
					answer += blank.GetCount();
					brickList.erase(brickList.begin() + j--);
					blankList.erase(blankList.begin() + i--);
					flag = true;
					break;
				}
			}
			
			if (flag)
				break;
		}
	}

	return answer;
}

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
class BrickLogger
{
public:
	void Log(Brick brick)
	{
		int size = brick.m_Points.size();
		for (int i = 0; i < size; ++i)
		{
			cout << brick.m_Points.top() << endl;
			brick.m_Points.pop();
		}
	}
};

int main()
{
	vector<vector<int>> game_board
	{
		{ 1, 1, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 1, 1, 0, 0 },
	};
	vector<vector<int>> table
	{
		{ 1, 0, 0, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 1, 1, 0, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0 },
	};

	cout << solution(game_board, table) << endl;

	return 0;
}