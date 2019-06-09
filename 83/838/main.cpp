#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        string result(dominoes);
        int start = -1, end = 0;
        int i;
        while (end < dominoes.size()) {
            switch(dominoes[end]) {
            case 'L':
                if ((start == -1) || (dominoes[start] == 'L')) {
                    for (i = start + 1; i < end; ++i) result[i] = 'L';
                } else if (dominoes[start]) {
                    for (i = 1 ; start + i < end - i; ++i) {
                        result[start + i] = 'R';
                        result[end - i] = 'L';
                    }
                }
                start = end;
                break;
            case 'R':
                if ((start != -1) && (result[start] == 'R')) {
                    for (i = start; i < end; ++i) result[i] = 'R';
                }
                start = end;
                break;
            }
            ++end;
        }
        if (dominoes[start] == 'R') {
            for (i = start + 1; i < end; ++i) result[i] = 'R';
        }
        return result;
	}
};

int main(int argc, char* argv[])
{
    string str;
	getline(std::cin, str);
    Solution solution;
    cout << str << endl;
    string result = solution.pushDominoes(str);
	cout << result << endl;
    cout << "\"" << str << "\"" << endl;

    return 0;
}
