#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

struct Node {
    Node() : isLeaf(false), children(26, NULL) {}
    bool isLeaf;
    vector<Node*> children;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        static const int MAX_LENGTH = 10000;
        root = new Node();
        rroot = new Node();
        vector<vector<int>> lenToIdx(MAX_LENGTH + 1);
        int i;
        for (i = 0; i < words.size(); ++i) {
            lenToIdx[words[i].length()].push_back(i);
        }
        for (i = 1; i <= MAX_LENGTH; ++i) {
            for (int idx : lenToIdx[i]) {
                if (checkNode(root, words[idx], 0, i - 1)) {
                    ret.push_back(words[idx]);
                }
            }
            for (int idx : lenToIdx[i]) {
                insertNode(root, words[idx], 0);
                insertRNode(rroot, words[idx], i - 1);
            }
        }
        return ret;
    }

private:
    void insertNode(Node* cur, string& word, int i) {
        Node*& local = cur->children[word[i] - 'a'];
        if (local == NULL) {
            Node* newNode = new Node();
            newNode->children.resize(26, NULL);
            local = newNode;
        }
        if (i == word.length() - 1) {
            local->isLeaf = true;
        } else {
            insertNode(local, word, i + 1);
        }
    }

    void insertRNode(Node* cur, string& word, int i) {
        Node*& local = cur->children[word[i] - 'a'];
        if (local == NULL) {
            Node* newNode = new Node();
            newNode->children.resize(26, NULL);
            local = newNode;
        }
        if (i == 0) {
            local->isLeaf = true;
        } else {
            insertRNode(local, word, i - 1);
        }
    }

    bool checkNode(Node* cur, string& word, int i, int end) {
        Node*& local = cur->children[word[i] - 'a'];
        if (local == NULL) {
            return false;
        } else if (i == end) {
            return local->isLeaf;
        } else if (checkNode(local, word, i + 1, end)) {
            return true;
        } else {
            return (local->isLeaf && checkRNode(rroot, word, i + 1, end));
        }
    }

    bool checkRNode(Node* cur, string& word, int start, int i) {
        Node*& local = cur->children[word[i] - 'a'];
        if (local == NULL) {
            return false;
        } else if (i == start) {
            return local->isLeaf;
        } else if (checkRNode(local, word, start, i - 1)) {
            return true;
        } else {
            return (local->isLeaf && checkNode(root, word, start, i - 1));
        }
    }

private:
    Node* root;
    Node* rroot;
};

int main(int argc, char* argv[])
{
    // input
    vector<string> valueVec;
    Input(valueVec);

    // solution
    Solution solution;
    vector<string> ret = solution.findAllConcatenatedWordsInADict(valueVec);

    // output
    Output(ret);

    return 0;
}
