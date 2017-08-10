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

bool operator<(const Interval& i1, const Interval& i2) {
	return (i1.start < i2.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		if (0 == intervals.size()) {
			return result;
		}
		std::sort(intervals.begin(), intervals.end());

		int i;
		int curStart = intervals[0].start;
		int curEnd = intervals[0].end;
		bool undefined = true;
		for (i=0; i<intervals.size(); ++i) {
			if (undefined) {
				curStart = intervals[i].start;
				curEnd = intervals[i].end;
				undefined = false;
			} else {
				if (intervals[i].start <= curEnd) {
					if (intervals[i].end > curEnd) {
						curEnd = intervals[i].end;
					}
				} else {
					result.push_back(Interval(curStart, curEnd));
					curStart = intervals[i].start;
					curEnd = intervals[i].end;
				}
			}
		}

		if (!undefined) {
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
	result = solution.merge(intervals);
	for (i=0; i<result.size(); ++i) {
		cout << result[i].start << " " << result[i].end << endl;
	}

    return 0;
}
