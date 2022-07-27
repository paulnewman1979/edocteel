#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root.addChar(word, 0);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root.search(word, 0);
    }

public:
    struct WordChar{
        WordChar() { endWord = false; }
        void addChar(string word, uint32_t pos) {
            WordChar& son = next[word[pos]];
            if (pos + 1 < word.length()) {
                son.addChar(word, pos + 1);
            } else {
                son.addChar();
            }
        }
        void addChar() {
            endWord = true;
        }
        bool search(string word, uint32_t pos) const {
            map<char, WordChar>::const_iterator iter;
            if (word[pos] != '.') {
                iter = next.find(word[pos]);
                if (iter == next.end()) {
                    return false;
                } else if (pos + 1 == word.length()) {
                    return ((iter->second.isEnd()) ? true : false);
                } else {
                    return (iter->second.search(word, pos + 1));
                }
            } else {
                iter = next.begin();
                if (pos + 1 == word.length()) {
                    while (iter != next.end()) {
                        if (iter->second.isEnd()) {
                            return true;
                        }
                        ++iter;
                    }
                } else {
                    while (iter != next.end()) {
                        if (iter->second.search(word, pos + 1)) {
                            return true;
                        }
                        ++iter;
                    }
                }
            }
            return false;
        }

        bool isEnd() const {
            return endWord;
        }

        map<char, WordChar> next;
        bool endWord;
    };

private:
    WordChar root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main(int argc, char* argv[])
{
    WordDictionary obj;
    char ch;
    string word;

    cin >> ch;
    while (ch != 'n') {
        cin >> word;
        switch(ch) {
            case 'a':
                obj.addWord(word);
                break;
            case 's':
            default:
                cout << (obj.search(word) ? "true" : "false" ) << endl;
                break;
        }
        cin >> ch;
    }

    return 0;
}
