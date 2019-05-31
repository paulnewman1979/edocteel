#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, int> keys;
        vector<int> todo;
        keys[0] = 1;
        todo.push_back(0);
        int i;
        while (todo.size() > 0) {
            i = todo.back();
            todo.pop_back();
            for (auto j: rooms[i]) {
                keys[j]++;
                if (keys[j] == 1) {
                    todo.push_back(j);
                }
            }
        }

        //cout << "keysize=" << keys.size() << " rooms.size=" << rooms.size() << endl;
        return (keys.size() == rooms.size());
    }
};

int main(int argc, char* argv[])
{
    vector< vector<int> > lines;

    int n;
    int n1;
    int value;
    vector<int> line;

    cin >> n;
    while (n > 0) {
        cin >> n1;
        line.clear();
        while (n1 > 0) {
            cin >> value;
            line.push_back(value);
            --n1;
        }
        lines.push_back(line);
        --n;
    }

    Solution solution;
    cout << (solution.canVisitAllRooms(lines) ? "true" : "false") << endl;

    return 0;
}
