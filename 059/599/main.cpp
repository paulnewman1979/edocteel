#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ret;
        unordered_map<string, int> listMap;
        unordered_map<string, int>::iterator iter;
        int i, j = - list1.size() - list2.size();
        for (i = 0; i < list1.size(); ++i) {
            listMap[list1[i]] = i;
        }
        for (i = 0; i < list2.size(); ++i) {
            iter = listMap.find(list2[i]);
            if (iter != listMap.end()) {
                iter->second = - iter->second - i;
                if (iter->second > j) j = iter->second;
            }
        }
        for (iter = listMap.begin(); iter != listMap.end(); ++iter) {
            if (iter->second == j) ret.push_back(iter->first);
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> list1;
    vector<string> list2;
    Input(list1);
    Input(list2);

    // solution
    Solution solution;
    vector<string> ret = solution.findRestaurant(list1, list2);

    // output
    Output(ret);

    return 0;
}
