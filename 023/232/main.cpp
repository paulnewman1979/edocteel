#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        _reverse = false;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (_reverse) {
            reverseStack();
            _reverse = false;
        }
        _queue.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result;
        if (!_reverse) {
            reverseStack();
            _reverse = true;
        }
        result = _queue.top();
        _queue.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if (!_reverse) {
            reverseStack();
            _reverse = true;
        }
        return _queue.empty() ? 0 : _queue.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _queue.empty();
    }

private:
    void reverseStack() {
        stack<int> newQueue;
        while (!_queue.empty()) {
            newQueue.push(_queue.top());
            _queue.pop();
        }
        newQueue.swap(_queue);
    }

    bool _reverse;
    stack<int> _queue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */


int main(int argc, char* argv[])
{
    int action;
    int num;

    MyQueue queue;

    cin >> action;
    while (action != -999999) {
        switch(action) {
        case 1:
            cin >> num;
            cout << "action: pushing " << num << endl;
            queue.push(num);
            break;
        case 2:
            num = queue.pop();
            cout << "action: poping " << num << endl;
            break;
        case 3:
            num = queue.peek();
            cout << "action: peek " << num << endl;
            break;
        case 4:
            cout << "empty? " << (queue.empty()?"yes":"no") << endl;
            break;
        }

        cin >> action;
    }

    return 0;
}
