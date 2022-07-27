#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
        if (0 == numerator) {
            return "0";
        } else if (0 == denominator) {
            return "";
        }

        long long numeratorLong = numerator;
        long long denominatorLong = denominator;
        ostringstream oss;
        if (numeratorLong < 0LL) {
            numeratorLong = -numeratorLong;
            if (denominatorLong < 0LL) {
                denominatorLong = -denominatorLong;
            } else {
                oss << "-";
            }
        } else if (denominatorLong < 0LL) {
            denominatorLong = -denominatorLong;
            oss << "-";
        }

        long long integerPart = 0;
        unordered_map<long long, long long> numeratorLongMap;
        if (numeratorLong > denominatorLong) {
            integerPart = numeratorLong / denominatorLong;
            numeratorLong = numeratorLong % denominatorLong;
            oss << integerPart;
            if (numeratorLong > 0) {
                oss << ".";
            } else {
                return oss.str();
            }
        } else {
            oss << "0.";
        }

        unordered_map<long long, long long>::const_iterator iter;
        do {
            numeratorLongMap[numeratorLong] = oss.str().length();
            numeratorLong = (numeratorLong << 3) + (numeratorLong << 1);
            oss << (numeratorLong / denominatorLong);
            numeratorLong = numeratorLong % denominatorLong;

            iter = numeratorLongMap.find(numeratorLong);
        } while ((numeratorLong != 0) && (iter == numeratorLongMap.end()));

        if (numeratorLong == 0) {
            return oss.str();
        } else {
            long long pos = iter->second;
            return oss.str().substr(0, pos) + "(" + oss.str().substr(pos) + ")";
        }
    }
};

int main(int argc, char* argv[])
{
	int n;
	int k;
	cin >> n;
	cin >> k;

    Solution solution;
	cout << solution.fractionToDecimal(n, k) << endl;

    return 0;
}
