#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef pair<double, int> RatioIndex;
bool operator<(RatioIndex& a, RatioIndex& b) {
    return (a.first < b.first);
}

class Solution {
public:
    double mincostToHireWorkers(const vector<int>& quality, const vector<int>& wage, const int K) {
        int size = quality.size();
        vector<RatioIndex> ratioIndex;
        vector<int> values;
        int i;

        // sort worker by wage/quality ratio
        for (i = 0 ; i < size; ++i) {
            ratioIndex.push_back(make_pair(wage[i] * 1.0/ quality[i], i));
        }
        sort(ratioIndex.begin(), ratioIndex.end());

        // get globally minimal quality sum
        values = quality;
        sort(values.begin(), values.end());
        int minimalQualitySum = 0;
        for (i = 0; i < K; ++i) {
            minimalQualitySum += values[i];
        }

        // initial with the minimal K ratio
        double minRatio = ratioIndex[K - 1].first;
        int minQualitySum = 0;
        vector<int> qualityHeap;
        for (i = 0; i < K; ++i) {
            minQualitySum += quality[ratioIndex[i].second];
            qualityHeap.push_back(quality[ratioIndex[i].second]);
        }
        make_heap(qualityHeap.begin(), qualityHeap.end());
        double minSumWage = minRatio * minQualitySum;
        int curQualitySum = minQualitySum;

        while (i < size) {
            double curRatio = ratioIndex[i].first;
            if (curRatio * minimalQualitySum > minSumWage) {
                break;
            }

            // calculate the real sum
            qualityHeap.push_back(quality[ratioIndex[i].second]);
            push_heap(qualityHeap.begin(), qualityHeap.end());
            pop_heap(qualityHeap.begin(), qualityHeap.end());
            curQualitySum += quality[ratioIndex[i].second];
            curQualitySum -= qualityHeap.back();
            qualityHeap.pop_back();
            if (curQualitySum * curRatio < minSumWage) {
                minRatio = curRatio;
                minQualitySum = curQualitySum;
                minSumWage = minQualitySum * minRatio;
            }

            ++i;
        }

        return minSumWage;;
    }
};

int main(int argc, char* argv[])
{
    int K;
    int n;
    vector<int> quality;
    vector<int> wage;
    int value;

    cin >> K;

    cin >> n;
    while (n > 0) {
        cin >> value;
        quality.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        wage.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.mincostToHireWorkers(quality, wage, K) << endl;

    return 0;
}
