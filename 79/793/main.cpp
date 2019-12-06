#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        vector<unsigned long long int > count;
        vector<unsigned long long int> sum;
        count.push_back(1);
        sum.push_back(1);
        while (sum.back() < K) {
            count.push_back(count.back() + 1);
            sum.push_back(sum.back() * 5 + 1);
        }
        int index = sum.size() - 1;
        while (K > 0) {
            if (sum[index] == K) {
                return 5;
            } else if (sum[index] - count[index] < K) {
                return 0;
            } else {
                --index;
                K = (K + sum[index] - 1) % sum[index] + 1;
            }
        }
        return 5;
    }
};

int main(int argc, char* argv[])
{
    // input
    int K;
    Input(K);

    // solution
    Solution solution;
    int ret = solution.preimageSizeFZF(K);

    // output
    Output(ret);

    return 0;
}
