#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void subGenerateRight(vector<string>& result, const string& prefix, const int left, const int right)
    {
        int i;
        string localPrefix = prefix;
        for (i=1; i<=right - left; ++i) {
            localPrefix += ")";
            subGenerateLeft(result, localPrefix, left, right - i);
        }
    }

    void subGenerateLeft(vector<string>& result, const string& prefix, const int left, const int right)
    {
        int i;
        string localPrefix = prefix;
        for (i=1; i<left; ++ i) {
            localPrefix += "(";
            subGenerateRight(result, localPrefix, left - i, right);
        }
        localPrefix += "(";
        for (i=1; i<=right; ++ i) {
            localPrefix += ")";
        }
        result.push_back(localPrefix);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) {
            return result;
        }

        string prefix = "";
        int left = n;
        int right = n;
        subGenerateLeft(result, prefix, left, right);

        return result;
    }
};

int main(int argc, char* argv[]) {
    int n;
    n = atoi(argv[1]);

    Solution solution;
    vector<string> result = solution.generateParenthesis(n);
    for (unsigned int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }
    
    return 0;
}
