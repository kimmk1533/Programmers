#include <string>
#include <vector>
using namespace std;

class Time
{
public:
	int day, hour, min, sec, ms;

	Time()
	{
		day = 0;
		hour = 0;
		min = 0;
		sec = 0;
		ms = 0;
	}
	Time(const int day, const int hour, const int min, const int sec, const int ms)
	{
		this->day = day;
		this->hour = hour;
		this->min = min;
		this->sec = sec;
		this->ms = ms;
	}

	void Sort()
	{
		if (ms < 0)
		{
			ms += 1000;
			--sec;
		}
		else if (ms >= 1000)
		{
			ms -= 1000;
			++sec;
		}

		if (sec < 0)
		{
			sec += 60;
			if (--min < 0)
			{
				min += 60;
				if (--hour < 0)
				{
					hour += 24;
					--day;
				}
			}
		}
		else if (sec >= 60)
		{
			sec -= 60;
			if (++min > 60)
			{
				min -= 60;
				if (++hour > 24)
				{
					hour -= 24;
					++day;
				}
			}
		}
	}

	Time operator+ (const Time& other)
	{
		return Time(day + other.day, hour + other.hour, min + other.min, sec + other.sec, ms + other.ms);
	}
	Time operator- (const Time& other)
	{
		return Time(day - other.day, hour - other.hour, min - other.min, sec - other.sec, ms - other.ms);
	}

	bool operator> (const Time& other) const
	{
		if (day == other.day)
		{
			if (hour == other.hour)
			{
				if (min == other.min)
				{
					if (sec == other.sec)
						return ms > other.ms;

					return sec > other.sec;
				}

				return min > other.min;
			}

			return hour > other.hour;
		}

		return day > other.day;
	}
	bool operator>= (const Time& other) const
	{
		return *this == other || *this > other;
	}
	bool operator< (const Time& other) const
	{
		if (day == other.day)
		{
			if (hour == other.hour)
			{
				if (min == other.min)
				{
					if (sec == other.sec)
						return ms < other.ms;

					return sec < other.sec;
				}

				return min < other.min;
			}

			return hour < other.hour;
		}

		return day < other.day;
	}
	bool operator<= (const Time& other) const
	{
		return *this == other || *this < other;
	}
	bool operator== (const Time& other) const
	{
		return hour == other.hour && min == other.min && sec == other.sec && ms == other.ms;
	}
};

class Log
{
public:
	Time start, end;

	Log(const string& line)
	{
		int day = stoi(line.substr(8, 2));
		int hour = stoi(line.substr(11, 2));
		int min = stoi(line.substr(14, 2));
		int sec = stoi(line.substr(17, 2));
		int ms = stoi(line.substr(20, 3));

		string processingTime = line.substr(24);
		processingTime.pop_back();
		int t_sec = stoi(processingTime.substr(0, 1)), t_ms = 0;
		if (processingTime.size() > 1)
			t_ms = stoi(processingTime.substr(2));

		end = Time(day, hour, min, sec, ms);
		start = Time(day, hour, min, sec - t_sec, ms - t_ms + 1);
		start.Sort();
	}

	bool operator< (const Log& other) const
	{
		if (start == other.start)
			return end < other.end;

		return start < other.start;
	}
};

int solution(vector<string> lines)
{
	vector<Time> times;
	vector<Log> logs;
	for (string line : lines)
	{
		Log log = Log(line);
		logs.push_back(log);

		times.push_back(log.start);
		times.push_back(log.end);
	}

	const Time oneSec = Time(0, 0, 0, 0, 999);
	int answer = 0;
	for (Time& time : times)
	{
		Time end = time + oneSec;
		end.Sort();
		int cnt = 0;
		for (const Log& log : logs)
		{
			if (log.start <= end && log.end >= time)
				++cnt;
		}
		answer = max(answer, cnt);
	}

	return answer;
}

#include <iostream>

int main()
{
	cout << solution(
		{
			"2016-09-15 12:00:00.000 3s"
		}
	) << endl;
	cout << solution(
		{
			"2016-09-15 00:00:00.000 3s"
		}
	) << endl;
	cout << solution(
		{
			"2016-09-15 01:00:04.001 2.0s",
			"2016-09-15 01:00:07.000 2s",
		}
		) << endl;
	cout << solution(
		{
			"2016-09-15 01:00:04.002 2.0s",
			"2016-09-15 01:00:07.000 2s"
		}
	) << endl;
	cout << solution(
		{
			"2016-09-15 20:59:57.421 0.351s",
			"2016-09-15 20:59:58.233 1.181s",
			"2016-09-15 20:59:58.299 0.8s",
			"2016-09-15 20:59:58.688 1.041s",
			"2016-09-15 20:59:59.591 1.412s",
			"2016-09-15 21:00:00.464 1.466s",
			"2016-09-15 21:00:00.741 1.581s",
			"2016-09-15 21:00:00.748 2.31s",
			"2016-09-15 21:00:00.966 0.381s",
			"2016-09-15 21:00:02.066 2.62s"
		}
	) << endl;

	return 0;
}