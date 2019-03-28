#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef pair<int, int> PosIndex;
bool operator<(PosIndex& a, PosIndex& b) {
    return a.first < b.first;
}

class Solution {
public:
    string findReplaceString(const string& S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<PosIndex> todo;
        int size = S.length();
        int i, j, k;
        int pos, index;
        for (i = 0; i < indexes.size(); ++i) {
            j = 0;
            while ((j + indexes[i] < S.length())
                    && (j < sources[i].length())
                    && (S[j + indexes[i]] == sources[i][j])) {
                ++j;
            }
            if (j == sources[i].length()) {
                index = i;
                pos = indexes[i];
                todo.push_back(make_pair(pos, index));
                size += targets[i].length();
                size -= sources[i].length();
            }
        }
        sort(todo.begin(), todo.end());

        if (todo.size() > 0) {
            string result(size, 0);
            i = 0;
            j = 0;
            k = 0;
            while (j < todo.size()) {
                index = todo[j].second;
                pos = todo[j].first;
                if (i < pos) {
                    result.replace(k, pos - i, S, i, pos - i);
                    k += pos - i;
                }
                result.replace(k, targets[index].length(), targets[index], 0, targets[index].length());
                k += targets[index].length();
                i = pos + sources[index].length();
                ++j;
            }
            if (i < S.length()) {
                result.replace(k, S.length() - i, S, i, S.length() - i);
            }
            return result;
        } else {
            return S;
        }
    }
};

int main(int argc, char* argv[])
{
    // parameters
    string S;
    vector<int> indexes;
    vector<string> sources;
    vector<string> targets;

    // tmp variables
    int n;
    int index;
    string value;

    // init data
    getline(cin, S);

    cin >> n;
    while (n > 0) {
        cin >> index;
        indexes.push_back(index);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        sources.push_back(value);
        --n;
    }

    cin >> n;
    while (n > 0) {
        cin >> value;
        targets.push_back(value);
        --n;
    }
        
    Solution solution;
    cout << solution.findReplaceString(S, indexes, sources, targets) << endl;

    return 0;
}
