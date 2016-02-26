#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> A(10, 0);
        vector<int> B(10, 0);
        int i;
        for (i=0; i<secret.length(); ++i) {
            A[secret[i]-'0']++;
            B[guess[i]-'0']++;
        }
        for (i=0; i<10; ++i) {
            B[i] = (A[i]>B[i])?B[i]:A[i];
            A[i] = 0;
        }
        for (i=0; i<secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                -- B[secret[i]-'0'];
                ++ A[secret[i]-'0'];
            }
        }
        int totalA = 0;
        int totalB = 0;
        for (i=0; i<10; ++i) {
            totalA += A[i];
            totalB += B[i];
        }
        std::ostringstream stream;
        stream << totalA << "A" << totalB << "B";
        return stream.str();
    }
};

int main(int argc, char* argv[])
{
    string secret;
    string guess;
    cin >> secret;
    cin >> guess;
    Solution solution;
    cout << solution.getHint(secret, guess) << endl;
}
