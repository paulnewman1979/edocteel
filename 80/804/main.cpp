#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

static const vector<string> MorseCodes{".-", "-...", "-.-.", "-..", ".",
                                       "..-.", "--.", "....", "..", ".---",
                                       "-.-", ".-..", "--", "-.", "---",
                                       ".--.", "--.-", ".-.", "...", "-",
                                       "..-", "...-", ".--", "-..-", "-.--",
                                       "--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> morseWord;
        for (auto word : words) {
            ostringstream oss;
            for (auto wchar : word) {
                oss << MorseCodes[wchar - 'a'];
            }
            morseWord.insert(oss.str());
        }
        return morseWord.size();;
    }
};

int main(int argc, char* argv[])
{
    // input
    vector<string> values;
    Input(values);

    // solution
    Solution solution;
    int ret = solution.uniqueMorseRepresentations(values);

    // output
    Output(ret);

    return 0;
}
