#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        if (N <= 11) { // 单独处理 11 以下的数，包括 11
            if (N <= 2)
                return 2;
            else if (N == 3)
                return 3;
            else if (N <= 5)
                return 5;
            else if (N <= 7)
                return 7;
            else
                return 11;
        }
        // when N > 11
        int modulus = N % 6; // 这个用来挑选余数为 1 或 5 的数字
        switch (modulus) {
        case 0:
            N++;
        case 1:
            modulus = 1;
            break;
        case 2:
            N++;
        case 3:
            N++;
        case 4:
            N++;
        case 5:
            modulus = 5;
            break;
        }
        vector<int> nums(10); // 这个用来判断回文数的，长度 10 就够用了
        for (;;) {
            int length = getNumLength(N, nums);
            if ((length & 1) == 0) {
                // if length is even, palindrome must be divided by 11
                N = (int) pow(10, length) + 1;
                modulus = 5; // modulus must be 5
                continue; // 跳过所有位数为偶数的数字
            }
            // here modulus must be 1 or 5
            if (isPalindrome(length, nums) && isPrime(N)) {
                return N;
            }
            // 步长为 2 或者 4，效率更高
            if (modulus == 1) {
                N += 4;
                modulus = 5;
            } else { // modulus == 5
                N += 2;
                modulus = 1;
            }
        }
    }

private:
    int getNumLength(int N, vector<int>& nums) {
        int length = 0;
        while (N > 0) {
            nums[length++] = N % 10;
            N /= 10;
        }
        return length;
    }

    bool isPrime(int num) {
        int sqrtNum = sqrt(num);
        // We have filtered nums what "N % 6 != 1 || N % 6 != 5"
        for (int i = 5; i <= sqrtNum; i += 6) {
            // So here just check "i % 6 == 1 || i % 6 == 5" 
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(int length, vector<int>& nums) {
        for (int i = 0; i < length / 2; i++) {
            if (nums[i] != nums[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    Solution solution;
    cout << solution.primePalindrome(n) << endl;

    return 0;
}
