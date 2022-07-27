#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

struct DictNode {
    DictNode(int len) :
        len_(len), next_(vector<DictNode*>(26, NULL)) {}
    int len_;
    vector<DictNode*> next_;
};

class Solution {
public:
    Solution() : root('\0') {}

    string replaceWords(vector<string>& dictionary, string sentence) {
        int i, j;
        stringstream str;

        for (i = 0; i < dictionary.size(); ++i) {
            insertDict(&root, dictionary[i], 0);
        }

        i = 0;
        bool first = true;
        while (i < sentence.length()) {
            j = i + 1;
            while ((j < sentence.length()) &&
                    (sentence[j] != ' ')) {
                ++j;
            }
            if (i < sentence.length()) {
                int len = findRoot(&root, sentence, j, i);
                if (0 == len) {
                    if (first) {
                        str << sentence.substr(i, j - i);
                        first = false;
                    } else {
                        str << " " << sentence.substr(i, j - i);
                    }
                } else {
                    if (first) {
                        str << sentence.substr(i, len);
                        first = false;
                    } else {
                        str << " " << sentence.substr(i, len);
                    }
                }
            }
            i = j + 1;
        }

        return str.str();
    }

private:
    void insertDict(DictNode* root, const string& word, const int i) {
        DictNode*& next = root->next_[word[i] - 'a'];
        if (next == NULL) {
            next = new DictNode(0);
        }
        if (i == word.length() - 1) {
            next->len_ = word.length();
        } else {
            insertDict(next, word, i + 1);
        }
    }

    int findRoot(const DictNode* root,
            const string& sentence,
            const int end,
            const int pos) {
        DictNode* next = root->next_[sentence[pos] - 'a'];
        if (next != NULL) {
            if (next->len_ > 0) {
                return next->len_;
            } else if (pos + 1 == end) {
                return 0;
            } else {
                return findRoot(next, sentence, end, pos + 1);
            }
        } else {
            return 0;
        }
    }

private:
    DictNode root;
};

int main(int argc, char* argv[])
{
    // input
    string sentence;
    vector<string> valueVec;
    Input(sentence);
    Input(valueVec);

    // solution
    Solution solution;
    string ret = solution.replaceWords(valueVec, sentence);

    // output
    Output(ret);

    return 0;
}
