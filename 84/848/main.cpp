#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

static vector<vector<char> > createShiftMap() {
    vector<vector<char> > shiftMap(26);
    int i, j;
    char ch;
    for (i = 0; i < 26; ++i) {
        ch = 'a' + i;
        for (j = 0; j < 26; ++j, ++ch) {
            if (i + j == 26) {
                ch = 'a';
            }
            shiftMap[i].push_back(ch);
        }
    }
    return shiftMap;
}

static vector<vector<char> > shiftMap = createShiftMap();

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string result(S);
        int i;
        int shiftTotal = 0;
        for (i = S.length() - 1; i >= 0; --i) {
            shiftTotal = (shiftTotal + shifts[i]) % 26;
            result[i] = shiftMap[S[i] - 'a'][shiftTotal];
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;

    string S;
    vector<int> values;
    int value;

    getline(cin, S);

    cin >> n;
    while (n > 0) {
        cin >> value;
        values.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.shiftingLetters(S, values) << endl;

    return 0;
}
