#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class Solution {
public:
    Solution(int n_rows, int n_cols) {
        _rows = n_rows;
        _cols = n_cols;
        _size = _rows * _cols;
        _marked.clear();
        srand(time(NULL));
    }
    
    vector<int> flip() {
        if (_marked.size() >= _size) return vector<int>();
        int value = rand(), row = (value & 0xffff) % _rows, col = ((value>>16) & 0xffff) % _cols;
        value = row + (col<<16);
        while (_marked.find(value) != _marked.end()) {
            value = rand();
            row = (value & 0xffff) % _rows;
            col = ((value>>16) & 0xffff) % _cols;
            value = row + (col<<16);
        }
        _marked.insert(value);
        return vector({row, col});
    }
    
    void reset() {
        _marked.clear();
    }
    
private:
    int _rows;
    int _cols;
    int _size;
    unordered_set<int> _marked;
};

int main(int argc, char* argv[])
{
    // input
    int rows, cols;
    vector<int> actions;
    Input(rows);
    Input(cols);
    Input(actions);

    // solution
    Solution solution(rows, cols);
    vector<int> ret;
	for (auto& action : actions) {
        if (action == 1) {
            ret = solution.flip();
            Output(ret);
        } else {
            solution.reset();
        }
    }

    return 0;
}
