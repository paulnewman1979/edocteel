#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <cstdlib>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

struct SubKey {
    SubKey() : _keyCount(0), _prefixCount(0), _subKey(26, NULL) {}
    int _keyCount;
    int _prefixCount;
    vector<SubKey*> _subKey;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        _root = new SubKey();
    }
    
    void insert(string key, int val) {
        int i = 0, diff = 0;
        SubKey* cur = _root;
        while ((i < key.length()) &&
                (cur->_subKey[key[i] - 'a'] != NULL)) {
            cur = cur->_subKey[key[i] - 'a'];
            ++i;
        }
        if (i < key.length()) {
            diff = val;
        } else {
            diff = val - cur->_keyCount;
        }

        cur = _root;
        i = 0;
        while (i < key.length()) {
            if (cur->_subKey[key[i] - 'a'] == NULL) {
                cur->_subKey[key[i] - 'a'] = new SubKey();
                cur = cur->_subKey[key[i] - 'a'];
                cur->_prefixCount = diff;
            } else {
                cur = cur->_subKey[key[i] - 'a'];
                cur->_prefixCount += diff;
            }
            ++i;
        }
        cur->_keyCount = val;
    }
    
    int sum(string prefix) {
        SubKey* cur = _root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (cur->_subKey[prefix[i] - 'a'] == NULL) {
                return 0;
            } else {
                cur = cur->_subKey[prefix[i] - 'a'];
            }
        }
        return cur->_prefixCount;
    }

private:
    SubKey* _root;
    vector<vector<int>> _keywords;
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<string>> actions;
    Input(actions);

    // solution
    MapSum ms;
    int i, ret;
    for (i = 0; i < actions.size(); ++i) {
        if (actions[i].size() == 2) {
            ms.insert(actions[i][0], atoi(actions[i][1].c_str()));
        } else {
            ret = ms.sum(actions[i][0]);
            Output(ret);
        }
    }

    return 0;
}
