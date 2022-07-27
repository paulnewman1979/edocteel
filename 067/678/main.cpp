#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        return checkValidString(s, 0, 0);
	}

private:
    bool checkValidString(const string& s, 
            const int pos,
            const int parCount) {
        if (pos == s.length()) {
            return (parCount == 0);
        } else {
            switch(s[pos]) {
              case '(':
                  return checkValidString(s, pos + 1, parCount + 1);
                break;
              case ')':
                  if (0 == parCount) return false;
                  return checkValidString(s, pos + 1, parCount - 1);
                break;
              default:
                if (checkValidString(s, pos + 1, parCount + 1)) return true;
                else if (checkValidString(s, pos + 1, parCount)) return true;
                else if ((parCount > 0) && (checkValidString(s, pos + 1, parCount - 1))) return true;
                else return false;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	bool ret = solution.checkValidString(str);

    // output
    Output(ret);

    return 0;
}
