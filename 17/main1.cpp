#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    void print_string(vector<string>& results, vector<int>& digit, int pos, string value) {
        char start;
        char end;
        if (digit[pos] == 7) {
            start = 'p';
            end = 's';
        }
        else if (digit[pos] == 8) {
            start = 't';
            end = 'v';
        }
        else if (digit[pos] == 9) {
            start = 'w';
            end = 'z';
        }
        else if (digit[pos] == 0) {
            start = ' ';
            end = ' ';
        }
        else if (digit[pos] == 1) {
        }
        else {
            start = 'a' + (digit[pos]-2)*3;
            end = 'a' + (digit[pos]-2)*3 + 2;
        }

        if (pos == 0) {
            for(char ch=start; ch<=end; ++ch) {
                results.push_back(value + ch);
            }
        }
        else {
            for (char ch=start; ch<=end; ++ch) {
                print_string(results, digit, pos - 1, value + ch);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.length() == 0) {
            return results;
        }
        string value = "";

        vector<int> digit;
        for (int i=digits.length()-1; i>=0; i--) {
            digit.push_back(int(digits[i] - '0'));
        }
        print_string(results, digit, digits.size()-1, value);
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums;
    string num;
    cin >> num;
    Solution solution;
    vector<string> values = solution.letterCombinations(num);
    for (int i=0; i< values.size(); ++i)
        cout << values[i] << endl;
}
