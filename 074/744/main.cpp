#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto upper = upper_bound(letters.begin(), letters.end(), target);
        return (upper == letters.end()) ? letters[0] : *upper;
    }
};

int main(int argc, char* argv[])
{
    // input
    char target;
    vector<char> valueVec;
    Input(target);
    Input(valueVec);

    // solution
    Solution solution;
    char ret = solution.nextGreatestLetter(valueVec, target);

    // output
    Output(ret);

    return 0;
}
