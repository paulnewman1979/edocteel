#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        unsigned int i = 0;
        for (; i < s.length(); ++i) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        unordered_map<char, int>::const_iterator iter1 = smap.begin();
        unordered_map<char, int>::const_iterator iter2;
        while (iter1 != smap.end()) {
            iter2 = tmap.find(iter1->first);
            if ((iter2 == tmap.end()) || (iter1->second != iter2->second)) return false;
            ++iter1;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	cin >> a;
	cin >> b;
    Solution solution;
	cout << (solution.isAnagram(a, b) ? "true" : "false") << endl;

    return 0;
}
