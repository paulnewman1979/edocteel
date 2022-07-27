#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        unsigned long long count = 0;
        int i, g, p;
        // countByGP means how many solution with
        // g people and p profit
        // while checking i-th (profit[i] & group[i])
        //  if (g <= G - group[i])
        //      if (p >= P - profit[i])
        //          countByGP[g + group[i]][P] += countByGP[g][p]
        //      else (p < P - profit[i])
        //          countByGP[g + group[i]][p + profit[i]] += countByGP[g][p]
        //
        vector<vector<int> > countByGP(G + 1, vector<int>(P + 1, 0));
        for (i = 0; i < group.size(); ++i) {
            //cout << "group[i]=" << group[i] << " profit[i]=" << profit[i] << endl;
            if (group[i] <= G) {
                for (g = G - group[i]; g >= 0; --g) {
                    for (p = P; p >= max(P - profit[i], 0); --p) {
                        countByGP[g + group[i]][P] += countByGP[g][p];
                        countByGP[g + group[i]][P] %= modulo;
                        //cout << "(" << (g + group[i]) << "," << P
                        //    << ") <- (" << g << "," << p << ")" << endl;
                    }
                    for (p = 0; p < max(P - profit[i], 0); ++p) {
                        countByGP[g + group[i]][p + profit[i]] += countByGP[g][p];
                        countByGP[g + group[i]][p + profit[i]] %=  modulo;
                        //cout << "(" << (g + group[i]) << "," << (p + profit[i])
                        //    << ") <- (" << g << "," << p << ")" << endl;
                    }
                }

                if (profit[i] < P) {
                    ++countByGP[group[i]][profit[i]];
                } else {
                    ++countByGP[group[i]][P];
                }
            }
        }

        count = 0;
        for (g = 1; g <= G; ++g) {
            count += countByGP[g][P];
        }
        return count % modulo;
    }

private:
    const static unsigned long long modulo = 1000000007;
};

int main(int argc, char* argv[])
{
    int G;
    int P;
    vector<int> group;
    vector<int> profit;

    int value;
    int n;


    cin >> G;
    cin >> P;
    cin >> n;
    while (n > 0) {
        cin >> value;
        group.push_back(value);
        --n;
    }
    cin >> n;
    while (n > 0) {
        cin >> value;
        profit.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.profitableSchemes(G, P, group, profit) << endl;

    return 0;
}
