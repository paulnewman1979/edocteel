#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        int i;
        int j;
        char ch;
        int max_length = 0;
        nums.resize(words.size(), 0);
        for (i=0; i<words.size(); ++i) {
            for (j=0; j<words[i].length(); ++j) {
                nums[i] |= (1<<(words[i][j] - 'a'));
            }
        }
        for (i=0; i<nums.size(); ++i) {
            for (j=i; j<nums.size(); ++j) {
                if ( (nums[i] & nums[j]) == 0) {
                    if (words[i].length() * words[j].length() > max_length) {
                        max_length = words[i].length() * words[j].length();
                    }
                }
            }
        }
        return max_length;
    }
};

int main(int argc, char* argv[]) {
    vector<string> words;
    string word;
    cin >> word;
    while (word != "-999999") {
        words.push_back(word);
        cin >> word;
    }
    Solution solution;
    int num = solution.maxProduct(words);
    cout << num << endl;
}
