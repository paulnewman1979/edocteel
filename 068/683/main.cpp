#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        if ((k >= flowers.size()) || (k < 0)) return -1;

        vector<int> slotLength(flowers.size() + 1, -1);
        slotLength[0] = flowers.size();
        int i, posj, posi;
        for (i = 0; i < flowers.size(); ++i) {
            posi = flowers[i];
            posj = posi;
            while (slotLength[posj] == -1) --posj;
            slotLength[posi] = posj + slotLength[posj] - posi;
            slotLength[posj] = posi - posj - 1;
            //cout << posi << "\t" << slotLength[posi] << endl;
            //cout << posj << "\t" << slotLength[posj] << endl << endl;
            if ((slotLength[posi] == k) && (posi + k < flowers.size())) return i + 1;
            if ((slotLength[posj] == k) && (posj != 0)) return i + 1;
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int flower;
    int k;
    vector<int> flowers;

    cin >> k;
    cin >> n;
    while (n > 0) {
        cin >> flower;
        flowers.push_back(flower);
        --n;
    }
        
    Solution solution;
    cout << solution.kEmptySlots(flowers, k) << endl;

    return 0;
}
