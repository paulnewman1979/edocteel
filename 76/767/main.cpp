#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

typedef pair<char, int> CharFreq;

bool compare(CharFreq& a, CharFreq& b) {
    return (b.second < a.second);
}

class Solution {
public:
    string reorganizeString(string S) {
        string ret;
        int j, k = 0;
        vector<CharFreq> count(26, make_pair('a', 0));
        for (auto c : S) {
            count[c - 'a'].first = c;
            count[c - 'a'].second++;
        }
        int size = (S.length() + 1) / 2;
        for (auto i : count) {
            if (i.second > size) return ret;
        }

        sort(count.begin(), count.end(), compare);
        ret = S;
        for (auto i : count) {
            j = 0;
            while (j < i.second) {
                ret[k] = i.first;
                k += 2;
                if (k >= S.length()) {
                    k = 1;
                }
                ++j;
            }
        }
        return ret;
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.reorganizeString(str);

    // output
    Output(ret);

    return 0;
}
