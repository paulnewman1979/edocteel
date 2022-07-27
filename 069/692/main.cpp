#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

bool descendSort(pair<int, string>& a, pair<int, string>& b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first < b.first) {
        return false;
    } else if (a.second < b.second) {
        return true;
    } else {
        return false;
    }
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string, int> wordFreq;
        unordered_map<string, int>::const_iterator wfIter;
        vector<pair<int, string> > freqWord;
        size_t i;
        for (i = 0; i < words.size(); ++i) {
            if (wordFreq.find(words[i]) != wordFreq.end()) {
                wordFreq[words[i]]++;
            } else {
                wordFreq[words[i]] = 1;
            }
        }
        for (wfIter = wordFreq.begin(); wfIter != wordFreq.end(); ++wfIter) {
            freqWord.push_back(make_pair(wfIter->second, wfIter->first));
        }
        sort(freqWord.begin(), freqWord.end(), descendSort);

        for (i = 0; (i < k) && (i < freqWord.size()); ++i) {
            result.push_back(freqWord[i].second);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    int n;
    int k;
    vector<string> words;
    vector<string> result;
    string word;

    cin >> k;
    cin >> n;
    while (n != 0) {
        cin >> word;
        words.push_back(word);
        --n;
    }
        
    Solution solution;
    result = solution.topKFrequent(words, k);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
