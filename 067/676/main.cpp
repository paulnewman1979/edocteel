#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    void buildDict(vector<string>& dictionary) {
        int i;
        char ch;
        for (auto& word: dictionary) {
            for (i = 0; i < word.length(); ++i) {
                ch = word[i];
                word[i] = '*';
                _dict[word] += 1;
                word[i] = ch;
            }
            _dict[word] -= 1;
        }
    }
    
    bool search(string& searchWord) {
        int count = (_dict.find(searchWord) == _dict.end()) ? 0 : -1;
        char ch;
        unordered_map<string, int>::const_iterator iter;
        int i = 0;
        for (; i < searchWord.length(); ++i) {
            ch = searchWord[i];
            searchWord[i] = '*';
            iter = _dict.find(searchWord);
            if ((iter != _dict.end()) &&
                    (iter->second + count > 0)) {
                searchWord[i] = ch;
                break;
            }
            searchWord[i] = ch;
        }
        return (i < searchWord.length());
    }

private:
    unordered_map<string, int> _dict;
};

int main(int argc, char* argv[])
{
    // input
    vector<string> dictionary;
    vector<string> searchWords;
    Input(dictionary);
    Input(searchWords);

    // solution
    bool ret = true;
    MagicDictionary md;
    md.buildDict(dictionary);
    for (auto& searchWord : searchWords) {
        ret = md.search(searchWord);
        Output(ret);
    }

    return 0;
}
