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
    string fractionAddition(string expression) {
        int M = 0, N = 1, index = 0;
        vector<int> curNum(2, 0);
        if (expression[0] == '-') curNum[1] = 1;
        bool positive = true;
        for (int i = 0; i < expression.length(); ++i) {
            switch(expression[i]) {
            case '+':
                M = positive ? (M * curNum[1] + curNum[0] * N) : (M * curNum[1] - curNum[0] * N);
                N = N * curNum[1];
                reduct(M, N);
                curNum[0] = curNum[1] = 0;
                positive = true;
                index = 0;
                break;
            case '-':
                M = positive ? (M * curNum[1] + curNum[0] * N) : (M * curNum[1] - curNum[0] * N);
                N = N * curNum[1];
                reduct(M, N);
                curNum[0] = curNum[1] = 0;
                positive = false;
                index = 0;
                break;
            case '/':
                index = 1;
                break;
            default:
                curNum[index] = curNum[index] * 10 + (expression[i] - '0');
            }
        }
        M = positive ? (M * curNum[1] + curNum[0] * N) : (M * curNum[1] - curNum[0] * N);
        N = N * curNum[1];
        reduct(M, N);

        stringstream ss;
        ss << M << "/" << N;
        return ss.str();
	}

private:
    void reduct(int& M, int& N) {
        if (M == 0) {
            N = 1;
            return;
        } else {
            bool negative = false;
            if (M < 0) negative = true;
            int m = (negative ? -M : M), n = N;
            while ((m > 0) && (n > 0)) {
                if (m > n) m = m % n;
                else n = n % m;
            }
            if (m == 0) {
                M = M / n;
                N = N / n;
            } else {
                M = M / m;
                N = N / m;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    // input
    string str;
    Input(str);

    // solution
    Solution solution;
	string ret = solution.fractionAddition(str);

    // output
    Output(ret);

    return 0;
}
