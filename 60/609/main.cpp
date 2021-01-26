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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> tmp;
        vector<vector<string>> ret;
        unordered_map<string, int> contentToIndex;
        unordered_map<string, int>::iterator iter;
        int i, j, k, l;
        string dir, filename, content;
        for (i = 0; i < paths.size(); ++i) {
            j = paths[i].find(" ");
            dir = paths[i].substr(0, j);
            ++j;
            while (j < paths[i].length()) {
                k = paths[i].find("(", j);
                filename = paths[i].substr(j, k - j);
                ++k;
                l = paths[i].find(")", k);
                content = paths[i].substr(k, l - k);

                iter = contentToIndex.find(content);
                if (iter == contentToIndex.end()) {
                    contentToIndex[content] = tmp.size();
                    tmp.push_back(vector<string>({dir + "/" + filename}));
                } else {
                    tmp[iter->second].push_back(dir + "/" + filename);
                }

                j = l + 2;
            }
        }
        for (auto& v: tmp) {
            if (v.size() > 1) ret.push_back(v);
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    vector<vector<string>> ret = solution.findDuplicate(valueVec);

    // output
    Output(ret);

    return 0;
}
