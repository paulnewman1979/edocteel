#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    void print_string(vector<string>& results, string& digits, int pos, string value) {
        static char mapping[10][2] = { {' ', ' '}, {' ', ' '}, {'a', 'c'}, {'d', 'f'}, {'g', 'i'}, {'j', 'l'}, {'m', 'o'}, {'p', 's'}, {'t', 'v'}, {'w', 'z'}};
        char start = mapping[digits[pos]-'0'][0];
        char end = mapping[digits[pos]-'0'][1];
        if (pos + 1 == digits.length()) {
            for(char ch=start; ch<=end; ++ch) {
                results.push_back(value + ch);
            }
        }
        else {
            for (char ch=start; ch<=end; ++ch) {
                print_string(results, digits, pos + 1, value + ch);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.length() == 0) {
            return results;
        }

        string value = "";
        print_string(results, digits, 0, value);
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
