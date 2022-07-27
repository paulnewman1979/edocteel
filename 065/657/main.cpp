#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int virtical = 0, horizontal = 0;
        for (int i = 0; i < moves.length(); ++i) {
            switch(moves[i]) {
            case 'U':
                --virtical;
                break;
            case 'D':
                ++virtical;
                break;
            case 'L':
                --horizontal;
                break;
            default:
                ++horizontal;
            }
        }

        return (virtical == 0) && (horizontal == 0);
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	bool ret = solution.judgeCircle(str);

    // output
    Output(ret);

    return 0;
}
