#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int num1 = 0;
        int num2 = 0;
        while (true) {
            while (i < version1.size()) {
                if (version1[i] == '.') {
                    break;
                }
                num1 = num1 * 10 + (version1[i] - '0');
                ++ i;
            }
            
            while (j < version2.size()) {
                if (version2[j] == '.') {
                    break;
                }
                num2 = num2 * 10 + (version2[j] - '0');
                ++ j;
            }
            
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            } else if ((i >= version1.size()) &&
                (j >= version2.size())) {
                return 0;
            }
            
            num1 = 0;
            num2 = 0;
            if (i < version1.size()) {
                ++ i;
            }
            
            if (j < version2.size()) {
                ++ j;
            }
        }
    }
};

int main(int argc, char* argv[])
{
	string a;
	string b;

	cin >> a;
	cin >> b;
    Solution solution;
	cout << solution.compareVersion(a, b) << endl;

    return 0;
}
