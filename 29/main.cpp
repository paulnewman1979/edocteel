#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (divisor == 0)
            {
                return INT_MAX;
            }
			else if ((divisor == -1) && (dividend == -0x80000000))
			{
				return INT_MAX;
			}

            int minus = 0;
            if (divisor > 0)
            {
                divisor = -divisor;
                minus = 1;
            }
            if (dividend > 0)
            {
                dividend = - dividend;
                minus = 1 - minus;
            }
            int count = 0;
            int base = 1;
            int base_divisor = divisor;
            while (dividend <= divisor)
            {
                base = 1;
                base_divisor = divisor;
                while ( (-0x40000000 < base_divisor)
                        && (dividend < base_divisor) )
                {
                    base_divisor = base_divisor<< 1;
                    base = base<< 1;
                }
                if (dividend > base_divisor)
                {
                    base_divisor = base_divisor>>1;
                    base = base>>1;
                    dividend -= base_divisor;
                    count += base;
                }
                else
                {
                    dividend -= base_divisor;
                    count += base;
                }
            }

            if (1 == minus)
            {
                count = -count;
            }

            return count;
        }
};

int main(int argc, char* argv[])
{
    int dividend;
    int divisor;
    cin >> dividend;
    cin >> divisor;

    Solution solution;
    cout << solution.divide(dividend, divisor) << endl;
}
