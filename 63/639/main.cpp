#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

const unsigned long long int MOD = 1000000007ULL;

class Solution {
public:
    int numDecodings(string s) {
        vector<unsigned long long int> count(2, 0);
        vector<int> num(2, 0);
        int index = 1, prevIndex, i;
        count[1] = 1;
        for (i = 0; i < s.length(); ++i) {
            prevIndex = index;
            index = 1 - index;
            switch(s[i]) {
              case '*':
                if (i > 0) {
                    switch(s[i - 1]) {
                      case '1':
                        count[index] = count[prevIndex] * 9 + count[index] * 9;
                        break;
                      case '2':
                        count[index] = count[prevIndex] * 9 + count[index] * 6;
                        break;
                      case '*':
                        count[index] = count[prevIndex] * 9 + count[index] * 15;
                        break;
                      default:
                        count[index] = count[prevIndex] * 9;
                    }
                } else {
                    count[index] = 9;
                }
                break;
              case '0':
                if (i == 0) {
                    return 0;
                } else {
                    switch(s[i - 1]) {
                      case '*':
                        count[index] = count[index] * 2;
                        break;
                      case '1':
                      case '2':
                        count[index] = count[index];
                        break;
                      default:
                        return 0;
                    }
                }
                break;
              case '7':
              case '8':
              case '9':
                if (i == 0) {
                    count[index] = 1;
                } else {
                    switch(s[i - 1]) {
                      case '*':
                      case '1':
                        count[index] = count[prevIndex] + count[index];
                        break;
                      default:
                        count[index] = count[prevIndex];
                    }
                }
                break;
              default:
                if (i == 0) {
                    count[index] = 1;
                } else {
                    switch(s[i - 1]) {
                      case '*':
                        count[index] = count[prevIndex] + count[index] * 2;
                        break;
                      case '1':
                      case '2':
                        count[index] = count[prevIndex] + count[index];
                        break;
                      default:
                        count[index] = count[prevIndex];
                    }
                }
            }
            count[index] %= MOD;
        }
        return count[index];
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	int ret = solution.numDecodings(str);

    // output
    Output(ret);

    return 0;
}
