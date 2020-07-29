#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class WordFilter {
public:
    WordFilter(vector<string>& words) : _size(words.size()) {
        int i, j, len;
        for (i = 0; i < _size; ++i) {
            len = words[i].length(); 
            for (j = 1; j < len; ++j) {
                _prefixMap[words[i].substr(0, j)].push_back(i);
                //cout << "prefix word=\"" << words[i].substr(0, j) << "\" index=" << i << endl;
                _suffixMap[words[i].substr(len - j, j)].push_back(i);
                //cout << "\tsuffix word=\"" << words[i].substr(len - j, j) << "\" index=" << i << endl;
            }
            _prefixMap[words[i]].push_back(i);
            _suffixMap[words[i]].push_back(i);
            //cout << "prefix word=\"" << words[i] << "\" index=" << i << endl;
            //cout << "\tsuffix word=\"" << words[i] << "\" index=" << i << endl;
        }
    }
    
    int f(string prefix, string suffix) {
        map<string, vector<int>>::const_iterator iter1;
        map<string, vector<int>>::const_iterator iter2;
        if (prefix == "") {
            if (suffix == "") {
                return (_size - 1);
            } else {
                iter1 = _suffixMap.find(suffix);
                return (iter1 != _suffixMap.end()) ? (iter1->second.back()) : -1;
            }
        } else if (suffix == "") {
            iter2 = _prefixMap.find(prefix);
            return (iter2 != _prefixMap.end()) ? (iter2->second.back()) : -1;
        } else {
            unordered_set<int> weightSet;
            iter1 = _prefixMap.find(prefix);
            iter2 = _suffixMap.find(suffix);
            if ((iter1 == _prefixMap.end()) ||
                    (iter2 == _suffixMap.end())) {
                return -1;
            } else {
                vector<int>::const_reverse_iterator it1 = iter1->second.rbegin();
                vector<int>::const_reverse_iterator it2 = iter2->second.rbegin();
                while ((it1 != iter1->second.rend()) &&
                        (it2 != iter2->second.rend())) {
                    if ((*it1) == (*it2)) {
                        return (*it1);
                    } else if ((*it1) > (*it2)) {
                        ++it1;
                    } else {
                        ++it2;
                    }
                }
            }
        }
        return 0;
    }

private:
    const int _size;
    map<string, vector<int>> _prefixMap;
    map<string, vector<int>> _suffixMap;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main(int argc, char* argv[])
{
	// input
	string prefix, suffix;
	vector<string> words;
	Input(prefix);
	Input(suffix);
	Input(words);

	// solution
    WordFilter wordFilter(words);
	int ret = wordFilter.f(prefix, suffix);

	// output
	Output(ret);

    return 0;
}
