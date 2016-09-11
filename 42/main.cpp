#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        int volume = 0;
        int i = 0;
        int j = height.size() - 1;
        int cur;
        while (i != j) {
            if (height[i] <= height[j]) {
                cur = i + 1;
                while (height[cur] < height[i]) {
                    volume += height[i] - height[cur];
                    ++ cur;
                }
                i = cur;
            } else {
                cur = j - 1;
                while (height[cur] < height[j]) {
                    volume += height[j] - height[cur];
                    -- cur;
                }
                j = cur;
            }
        }

        return volume;
    }
};

int main(int argc, char* argv[])
{
	int n;
	vector<int> height;

	cin >> n;
	while (n != -999999) {
		height.push_back(n);
		cin >> n;
	}

    Solution solution;
	cout << solution.trap(height) << endl;

    return 0;
}
