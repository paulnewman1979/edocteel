#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        _stack.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        std::queue<int> newStack;
        int size = _stack.size();
        while (size > 1) {
            newStack.push(_stack.front());
            _stack.pop();
            --size;
        }
        swap(_stack, newStack);
        return newStack.back();
    }

    /** Get the top element. */
    int top() {
        return _stack.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _stack.empty();
    }
private:
    std::queue<int> _stack;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main(int argc, char* argv[])
{
    int action;
    int num;

    MyStack stack;

    cin >> action;
    while (action != -999999) {
        switch(action) {
        case 1:
            cin >> num;
            cout << "action: pushing " << num << endl;
            stack.push(num);
            break;
        case 2:
            num = stack.pop();
            cout << "action: poping " << num << endl;
            break;
        case 3:
            num = stack.top();
            cout << "action: top " << num << endl;
            break;
        case 4:
            cout << "empty? " << (stack.empty()?"yes":"no") << endl;
            break;
        }

        cin >> action;
    }

    return 0;
}
