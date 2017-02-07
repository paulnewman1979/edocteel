#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Trie {
public:
    struct TrieNode {
        TrieNode(char c) {
            this->c = c;
            memset(child, 0, sizeof(child) * sizeof(TrieNode*));
        }
        ~TrieNode() {
            int i;
            for (i=0; i<26; ++i) {
                if (NULL != child[i]) {
                    delete child[i];
                }
            }
        }
        char c;
        TrieNode* child[27];
    };

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    ~Trie() {
        delete root;
        root = NULL;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int i;
        TrieNode* cur = root;
        for (i=0; i<word.length(); ++i) {
            if (cur->child[word[i]-'a'] == NULL) {
                break;
            }
            cur=cur->child[word[i]-'a'];
        }
        for (; i<word.length(); ++i) {
            cur->child[word[i]-'a'] = new TrieNode(word[i]);
            cur = cur->child[word[i]-'a'];
        }
        cur->child[26] = root;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i;
        TrieNode* cur = root;
        for (i=0; i<word.length(); ++i) {
            if (cur->child[word[i]-'a'] == NULL) {
                return false;
            }
            cur=cur->child[word[i]-'a'];
        }
        return (cur->child[26] == root)?true:false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i;
        TrieNode* cur = root;
        for (i=0; i<prefix.length(); ++i) {
            if (cur->child[prefix[i]-'a'] == NULL) {
                return false;
            }
            cur=cur->child[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(int argc, char* argv[])
{
    Trie obj;
    int n;
    string word;
    string prefix;

    cin >> n;
    while (n != -999999) {
        switch(n) {
        case 1:
            cin >> word;
            cout << "insert: " << word << endl;
            obj.insert(word);
            break;
        case 2:
            cin >> word;
            cout << "word: " << word << ", " << (obj.search(word)?"true":"false") << endl;
            break;
        case 3:
            cin >> prefix;
            cout << "prefix: " << prefix << ", " << (obj.startsWith(prefix)?"true":"false") << endl;
            break;
        default:
            cout << "hello" << endl;
            break;
        }

        cin >> n;
    }

    return 0;
}
