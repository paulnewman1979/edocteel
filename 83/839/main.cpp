#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int size = A.size();
        vector<int> group(size);
        int i, j;

        for (i = 0; i < A.size(); ++i) {
            group[i] = i;
        }

        for (i = 0; i < size; ++i) {
            for (j = i + 1; j < size; ++j) {
                if (isSimilar(A[i], A[j])) {
                    int p = findRoot(group, i);
                    int q = findRoot(group, j);
                    if (p < q) {
                        group[q] = p;
                    } else {
                        group[p] = q;
                    }
                }
            }
        }
        
        unordered_set<int> groupSet;
        for (i = 0; i < size; ++i) {
            groupSet.insert(findRoot(group, i));
        }

        return groupSet.size();
    }

private:
    bool isSimilar(const std::string& a, const std::string& b) {
        int i;
        int diffSize = 0;
        for (i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                if (++diffSize > 2) return false;
            }
        }
        return true;
    }

    int findRoot(vector<int>& group, int i) {
        while (i != group[i]) {
            i = group[i];
        }
        return i;
    }
};

int main(int argc, char* argv[])
{
    int n;
    vector<string> values;
    string value;

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.numSimilarGroups(values) << endl;

    return 0;
}
