#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"
#include <unordered_map>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        int i, j, nextIndex;
        char ch;
        string ret = T;
        unordered_map<char, int> index;
        for (i = 0; i < S.length(); ++i) {
            index[S[i]] = 0;
        }
        for (i = 0; i < T.length(); ++i) {
            if (index.find(T[i]) != index.end()) {
                index[T[i]]++;
            }
        }
        nextIndex = index[S[0]];
        index[S[0]] = 0;
        for (i = 1; i < S.length(); ++i) {
            swap(index[S[i]], nextIndex);
            nextIndex += index[S[i]];
        }
        j = 0;
        for (i = 0; i < T.length(); ++i) {
            ch = T[i];
            if (index.find(ch) != index.end()) {
                ret[index[ch]] = ch;
                ++index[ch];
            } else {
                ret[nextIndex] = ch;
                ++nextIndex;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    // input
	string a;
	string b;
    Input(a);
    Input(b);

    // solution
    Solution solution;
    string ret = solution.customSortString(a, b);

    // output
    Output(ret);

    return 0;
}
