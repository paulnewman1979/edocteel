#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ret;
        size_t i, j, k, l;
        string newLine;
        bool inComment = false;
        for (auto line : source) {
            k = 0;
            do {
                if (inComment) {
                    j = line.find("*/", k);
                    if (j == string::npos) break;
                    else {
                        inComment = false;
                        k = j + 2;
                    }
                } else {
                    i = line.find("/*", k);
                    l = line.find("//", k);
                    if ((l != string::npos) &&
                            ((i == string::npos) ||
                             (i > l))) {
                        newLine.append(line.substr(k, l - k));
                        if (newLine.length() > 0) {
                            ret.push_back(newLine);
                            newLine.clear();
                        }
                        break;
                    } else if (i != string::npos) {
                        inComment = true;
                        newLine.append(line.substr(k, i - k));
                        k = i + 2;
                    } else {
                        newLine.append(line.substr(k));
                        if (newLine.length() > 0) {
                            ret.push_back(newLine);
                            newLine.clear();
                        }
                        break;
                    }
                }
            } while (true);
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
    vector<string> ret = solution.removeComments(valueVec);

    // output
    Output(ret);

    return 0;
}
