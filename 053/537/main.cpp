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
    string complexNumberMultiply(string a, string b) {
        stringstream ss;
        int aReal, aImagine, bReal, bImagine, retReal, retImagine;
        getNumber(a, aReal, aImagine);
        getNumber(b, bReal, bImagine);
        retReal = aReal * bReal - aImagine * bImagine;
        retImagine = aReal * bImagine + aImagine * bReal;
        ss << retReal << "+" << retImagine << "i";
        return ss.str();
    }

private:
    void getNumber(string& a, int& realNumber, int& imaginaryNumber) {
        int size = a.length(), i = a.find("+"), j, start, end;
        start = (a[0] == '-') ? 1 : 0;
        end = i - 1;
        realNumber = 0;
        for (j = start; j <= end; ++j) {
            realNumber = realNumber * 10 + (a[j] - '0');
        }
        if (a[0] == '-') realNumber = -realNumber;

        start = (a[i + 1] == '-') ? i + 2 : i + 1;
        end = size - 2;
        imaginaryNumber = 0;
        for (j = start; j <= end; ++j) {
            imaginaryNumber = imaginaryNumber * 10 + (a[j] - '0');
        }
        if (a[i + 1] == '-') imaginaryNumber = -imaginaryNumber;
    }
};

int main(int argc, char* argv[])
{
    // input
	string a;
	string b;
    Input(a);
    Input(b);

    // solution
    Solution solution;
    string ret = solution.complexNumberMultiply(a, b);

    // output
    Output(ret);

    return 0;
}
