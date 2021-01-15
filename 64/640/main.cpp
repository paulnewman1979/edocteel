#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"


using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int num = 0, i, index = 0;
        bool isAdd = true;
        bool isNumValid = false;
        vector<int> xCount(2, 0);
        vector<int> valueCount(2, 0);
        i = 0;
        while (i < equation.length()) {
            switch(equation[i]) {
            case '+':
                if (isNumValid) valueCount[index] += isAdd ? num : -num;
                isAdd = true;
                isNumValid = false;
                num = 0;
                break;
            case '-':
                if (isNumValid) valueCount[index] += isAdd ? num : -num;
                isAdd = false;
                isNumValid = false;
                num = 0;
                break;
            case '=':
                if (isNumValid) valueCount[index] += isAdd ? num : -num;
                isAdd = true;
                index = 1;
                isNumValid = false;
                num = 0;
                break;
            case 'x':
                if (isNumValid) xCount[index] += isAdd ? num : -num;
                else xCount[index] += isAdd ? 1: -1;
                isNumValid = false;
                num = 0;
                break;
            default:
                num = num * 10 + (equation[i] - '0');
                isNumValid = true;
            }
            ++i;
        }
        if (num > 0) {
            valueCount[index] += isAdd ? num : -num;
        }

        stringstream ss;
        if (xCount[0] == xCount[1]) {
            if (valueCount[0] == valueCount[1]) {
                ss << "Infinite solutions";
            } else {
                ss << "No solution";
            }
        } else {
            ss << "x=" << ((valueCount[0] - valueCount[1]) / (xCount[1] - xCount[0]));
        }
        return ss.str();
	}
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.solveEquation(str);

    // output
    Output(ret);

    return 0;
}
