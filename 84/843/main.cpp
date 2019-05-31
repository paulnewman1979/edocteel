#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class Master {
public:
    Master(vector<string>& wordlist) : wordlist_(wordlist) {
        srand(time(NULL));
        index_ = rand() % wordlist_.size();
    }

    int guess(const string& word) const {
        int count = 0;
        for (int i = 0; i < 6; ++i) {
            if (word[i] == wordlist_[index_][i]) ++count;
        }
        return count;
    }

private:
    vector<string> wordlist_;
    int index_;
};

class Solution {
private:
    int matches(const string& left, const string& right) {
        int res = 0;
        for (int i = 0; i < 6; ++i) {
            if (left[i] == right[i]) {
                ++res;
            }
        }
        return res;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int index = rand() % wordlist.size();
        int x = master.guess(wordlist[index]);
        while (x < 6) {
            vector<string> newWordlist;
            for (int i = 0; i < wordlist.size(); ++i) {
                if (matches(wordlist[i], wordlist[index]) == x) {
                    newWordlist.push_back(wordlist[i]);
                }
            }
            wordlist = move(newWordlist);
            index = rand() % wordlist.size();
            x = master.guess(wordlist[index]);
        }
    }
};

int main(int argc, char* argv[])
{
    int n;
    string value;
    vector<string> wordlist;

    cin >> n;
    while (n > 0) {
        cin >> value;
        wordlist.push_back(value);
        --n;
    }

    Solution solution;
    Master master(wordlist);
    solution.findSecretWord(wordlist, master);

    return 0;
}
