#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        if (K == 1) return S.substr(0, 1);

        int i;
        vector<unsigned long long> len;
        len.push_back(0);
        for (i = 0; i < S.length(); ++i) {
            switch(S[i]) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                len.push_back(len.back() * (S[i] - '0'));
                break;
            default:
                len.push_back(len.back() + 1);
            }

            //cout << "stage 1:\t" << S[i] << "\t" << len.size() << "\t" << len.back() << endl;

            if (len.back() >= K) 
                break;
        }

        int k = K;
        for (i = len.size() - 1; i > 0; --i) {
            //cout << "stage 2:\t" << S[i - 1] << " " << k << endl;
            //cout << "\t\t" << S[i] << "\t" << len[i] << "\t" << len[i - 1] << endl;
            switch(S[i - 1]) {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                k = (k - 1) % len[i - 1] + 1;
                break;
            default:
                if (k == len[i]) {
                    return S.substr(i - 1, 1);
                }
            }
        }

        return S.substr(0, 1);;
    }
};

int main(int argc, char* argv[])
{
	string S;
	int K;

	cin >> S;
	cin >> K;
    Solution solution;
	string result = solution.decodeAtIndex(S, K);
    cout << result << endl;

    return 0;
}
