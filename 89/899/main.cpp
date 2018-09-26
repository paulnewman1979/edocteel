#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        int i, j, k;
        int maxI;

        string result;
        if (K > 1) {
            unordered_map<char, uint32_t> charMap;
            for (i = 0; i < S.length(); ++i) {
                charMap[S[i]]++;
            }
            for (char ch='a'; ch <= 'z'; ++ch) {
                if (charMap.find(ch) != charMap.end()) {
                    for (i = 0; i < charMap[ch]; ++i) {
                        result += ch;
                    }
                }
            }
        } else {
            maxI = 0;
            for (i = 1; i < S.length(); ++i) {
                j = i;
                k = maxI;
                do {
                    if (S[j] < S[k]) {
                        maxI = i;
                        break;
                    } else if (S[j] > S[k]) {
                        break;
                    }
                    if (++j >= S.length()) j = 0;
                    if (++k >= S.length()) k = 0;
                } while (j != i);
            }
            result = S.substr(maxI);
            result += S.substr(0, maxI);
        }
        return result;
	}
};

int main(int argc, char* argv[])
{
    int k;
    string str;

    cin >> k;
    cin >> str;
    Solution solution;
	cout << solution.orderlyQueue(str, k) << endl;

    return 0;
}
