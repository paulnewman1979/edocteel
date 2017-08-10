#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;

		if (0 == intervals.size()) {
			result.push_back(newInterval);
			return result;
		}

		int curStart = newInterval.start;
		int curEnd = newInterval.end;
		int status = 0;
		for (int i=0; i<intervals.size(); ++i) {
			if (0 == status) {
				if (intervals[i].end < curStart) {
					result.push_back(intervals[i]);
				} else if (intervals[i].start > curEnd) {
					result.push_back(Interval(curStart, curEnd));
					result.push_back(intervals[i]);
					status = 1;
				} else {
					if (intervals[i].end > curEnd) {
						curEnd = intervals[i].end;
					}
					if (intervals[i].start < curStart) {
						curStart = intervals[i].start;
					}
				}
			} else {
				result.push_back(intervals[i]);
			}
		}

		if (0 == status) {
			result.push_back(Interval(curStart, curEnd));
		}

		return result;
    }
};

int main(int argc, char* argv[])
{
	vector<Interval> intervals;
	vector<Interval> result;
	int count = 0;
	int s;
	int i;

	cin >> s;
	cin >> i;
	Interval newInterval(s, i);

	cin >> i;
	while (i != -999999) {
		if (0 == count) {
			s = i;
		} else {
			intervals.push_back(Interval(s,i));
		}
		count = 1 - count;

		cin >> i;
	}

    Solution solution;
	result = solution.insert(intervals, newInterval);
	for (i=0; i<result.size(); ++i) {
		cout << result[i].start << " " << result[i].end << endl;
	}

    return 0;
}
