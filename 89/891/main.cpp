#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        long long int maxModulo = 0, minModulo = 0, freq = 1;
        int i, ret;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size(); ++i) {
            maxModulo = (maxModulo + nums[i] * freq) % modulo;
            freq = (freq<<1) % modulo;
            //cout << "max: " << i << " " << maxModulo << endl;
        }
        freq = 1;
        for (i = nums.size() - 1; i >= 0; --i) {
            minModulo = (minModulo + nums[i] * freq) % modulo;
            freq = (freq<<1) % modulo;
            //cout << "max: " << i << " " << minModulo << endl;
        }
        ret = (int)(maxModulo - minModulo) % modulo;
        if (ret < 0) ret += modulo;

        return ret;
    }

private:
    static const int modulo = 1000000007;
};

int main(int argc, char* argv[])
{
    vector<int> values;
    Input(values);

    Solution solution;
    int ret = solution.sumSubseqWidths(values);

    Output(ret);

    return 0;
}
