#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

unsigned long long sMax = 2147483648ULL;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> results;
        unsigned long long s0 = 0;
        unsigned long long s1 = 0;
        int i, j;
        for (i = 1; i < S.length(); ++i) {
            if ((S[0] == '0') && (i > 1)) break;
            s0 = s0 * 10 + (S[i - 1] - '0');
            if (s0 > sMax) break;

            s1 = 0;
            for (j = i + 1; j < S.length(); ++j) {
                //cout << "i=" << i << " j=" << j << endl;
                if ((S[i] == '0') && (j - i > 1)) break;
                if ((j + i > S.length()) || (j + j - i > S.length())) break;
                s1 = s1 * 10 + (S[j - 1] - '0');
                if (s1 > sMax) break;
                results.clear();
                results.push_back(s0);
                results.push_back(s1);
                if (validate(S, s0, s1, j, results)) {
                    return results;
                }
            }
        }
        results.clear();
        return results;
	}

private:
    bool validate(string& S, unsigned long long s0, unsigned long long s1, int i, vector<int>& results) {
        //cout << "   validate " << s0 << " " << s1 << " i=" << i << endl;
        if (((s0 + s1) > 0) && (S[i] == '0')) return false;
        unsigned long long s2 = 0;
        do {
            s2 = s2 * 10 + (S[i] - '0');
            if (s2 > sMax) return false;
            ++i;
        }
        while ((i < S.length()) && (s2 < s0 + s1));
        if (s2 != s0 + s1) {
            //cout << "   validate false 1: s2=" << s2 << " s0=" << s0 << " s1=" << s1 << endl;
            return false;
        } else {
            results.push_back(s2);
            if (i == S.length()) {
                //cout << "   validate true: s2=" << s2 << " s0=" << s0 << " s1=" << s1 << endl;
                return true;
            } else {
                return validate(S, s1, s2, i, results);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);

    Solution solution;
    vector<int> results = solution.splitIntoFibonacci(str);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
