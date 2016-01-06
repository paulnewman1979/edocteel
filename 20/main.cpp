#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        char ch;
        for (int i=0; i<s.length(); ++i) {
            if ( (s[i] == '}')
                || (s[i] == ']')
                || (s[i] == ')') ) {
                if (stack.size() == 0) {
                    return false;
                } else {
                    ch = stack.back();
                    stack.pop_back();
                    if ( (s[i] == '}' && ch != '{')
                        || (s[i] == ')' && ch != '(')
                        || (s[i] == ']' && ch != '[') ) {
                        return false;
                    }
                }
            } else {
                stack.push_back(s[i]);
            }
        }

        return (stack.size() == 0)? true: false;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    solution.(argv[1]);
}
