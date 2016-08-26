#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
		minIndex = -1;
		size = 0;
    }
    
    void push(int x) {
		nums.push_back(x);
		++ size;
		if (1 == size) {
			minIndex = 0;
			curMinIndex.push_back(0);
		} else if (x < nums[minIndex]) {
			minIndex = size - 1;
			curMinIndex.push_back(minIndex);
		} else {
			curMinIndex.push_back(minIndex);
		}
    }
    
    void pop() {
		if (nums.size() > 0) {
			nums.pop_back();
			curMinIndex.pop_back();
			minIndex = curMinIndex.back();
			-- size;
		}
    }
    
    int top() {
		if (nums.size() > 0) {
			return nums.back();
		}
		return 0;
    }
    
    int getMin() {
		if (nums.size() > 0) {
			int index = curMinIndex.back();
			return nums[index];
		}
		return 0;
    }
private:
	std::vector<int> nums;
	std::vector<int> curMinIndex;
	int size;
	int minIndex;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(int argc, char* argv[])
{
	MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(-3 == minStack.getMin());
    minStack.pop();
    assert(0 == minStack.top());
    assert(-2 == minStack.getMin());
}
