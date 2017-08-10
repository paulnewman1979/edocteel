#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		if ((num1 == "0") || (num2 == "0")) {
			return "0";
		}

		int i, j, k;
		vector<int> tnum1;
		vector<int> tnum2;
		for (i=num1.length() - 1; i>=0; --i) {
			tnum1.push_back(num1[i] - '0');
		}
		for (i=num2.length() - 1; i>=0; --i) {
			tnum2.push_back(num2[i] - '0');
		}

		vector<int> result(tnum1.size() + tnum2.size(), 0);
		for (i=0; i<tnum1.size(); ++i) {
			for (j=0; j<tnum2.size(); ++j) {
				k = i + j;
				result[k] += tnum1[i] * tnum2[j];
				while (result[k] >= 10) {
					result[k+1] += result[k] / 10;
					result[k] %= 10;
					++ k;
				}
			}
		}

		string resultStr;
		if (result[result.size() - 1] == 0) {
			i = result.size() - 2;
		} else {
			i = result.size() - 1;
		}
		for (; i>=0; --i) {
			resultStr += ((char)('0' + result[i]));
		}

		return resultStr;
    }
};

int main(int argc, char* argv[])
{
	string num1;
	string num2; 

	cin >> num1;
	cin >> num2;

    Solution solution;
	cout << solution.multiply(num1, num2) << endl;

    return 0;
}
