#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) {
            return "1";
        }
        string cur = countAndSay(n - 1);
        string result = "";
        char ch = cur[0];
        int count = 1;
        int i;
        for (i=1; i<cur.length(); i++) {
            if (cur[i] == ch) {
                ++ count;
            } else {
                result += to_string(count);
                result += ch;
                count = 1;
                ch = cur[i];
            }
        }
        result += to_string(count);
        result += ch;

        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    Solution solution;
    cout << solution.countAndSay(n) << endl;
}
