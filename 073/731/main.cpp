#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

const int RANGE_MAX = 1000000000LL;

struct RangeCount {
    RangeCount(int rangeStart, int count) : rangeStart_(rangeStart), count_(count) {}
    int rangeStart_;
    int count_;
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        ranges.emplace_back(0, 0);
        ranges.emplace_back(RANGE_MAX, 0);
    }

    bool book(int start, int end) {
        int min, max, mid;

        // find start between ranges[min] and ranges[min + 1]
        min = 0;
        max = ranges.size();
        while (max >= min + 2) {
            mid  = (max + min) / 2;
            if (ranges[mid].rangeStart_ == start) {
                min = mid;
                break;
            } else if (ranges[mid].rangeStart_ > start) {
                max = mid;
            } else {
                min = mid;
            }
        }

        // check all ranges booked less than 2 times
        max = min;
        while ((max < ranges.size()) &&
                (ranges[max].rangeStart_ < end) &&
                (ranges[max].count_ < 2)) {
            ++max;
        }

        if (ranges[max].rangeStart_ < end) {
            //cout << "checking (" << start << ", " << end << ")" << endl << endl;
            return false;
        }
        else {
            max = min + 1;
            int newStart = start;
            bool done = false;
            while (!done) {
                if (newStart > ranges[min].rangeStart_) {
                    ranges.emplace(ranges.begin() + max, newStart, ranges[min].count_);
                } else if (end > ranges[max].rangeStart_) {
                    ranges[min].count_++;
                    newStart = ranges[max].rangeStart_;
                } else if (end == ranges[max].rangeStart_) {
                    ranges[min].count_++;
                    newStart = ranges[max].rangeStart_;
                    done = true;
                } else {
                    ranges[min].count_++;
                    ranges.emplace(ranges.begin() + max, end, ranges[min].count_ - 1);
                    done = true;
                }
                ++min;
                ++max;
            }
        }

        // debug
        //cout << "checking (" << start << ", " << end << ")" << endl;
        //for (auto r: ranges) {
        //    cout << "\t" << r.rangeStart_ << ", " << r.count_ << endl;
        //}
        //cout << endl;

        return true;
    }

private:
    vector<RangeCount> ranges;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * int param_1 = obj->book(start,end);
 */

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueGrid;
    Input(valueGrid);

    // solution
	MyCalendarTwo myCal2;
    bool ret;
    for (auto value : valueGrid) {
        ret = myCal2.book(value[0], value[1]);
        // output
        Output(ret);
    }
    
    return 0;
}
