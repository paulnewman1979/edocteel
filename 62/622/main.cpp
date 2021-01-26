#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        _queueSize = k + 1;
        _queue.resize(_queueSize);
        _queueStart = 0;
        _queueEnd = 0;
    }
    
    bool enQueue(int value) {
        if (_queueStart == _queueSize - 1) {
            if (_queueEnd == 0) {
                return false;
            } else {
                _queueStart = 0;
                _queue[_queueStart] = value;
                return true;
            }
        } else if (_queueStart + 1 == _queueEnd) {
            return false;
        } else {
            ++_queueStart;
            _queue[_queueStart] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        else if (_queueEnd == _queueSize - 1) {
            _queueEnd = 0;
            return true;
        } else {
            ++_queueEnd;
            return true;
        }
    }
    
    int Front() {
        if (!isEmpty()) {
            return (_queueEnd == _queueSize - 1) ? _queue[0] : _queue[_queueEnd + 1];
        } else return -1;
    }
    
    int Rear() {
        if (!isEmpty()) return _queue[_queueStart];
        else return -1;
    }
    
    bool isEmpty() {
        return _queueStart == _queueEnd;
    }
    
    bool isFull() {
        if (_queueStart == _queueSize - 1) {
            if (_queueEnd == 0) return true;
            else return false;
        } else return (_queueStart + 1 == _queueEnd);
    }

private:
    vector<int> _queue;
    int _queueStart;
    int _queueEnd;
    int _queueSize;
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<string>> actions;
    Input(actions);

    // solution
    MyCircularQueue* mcq = NULL;
    int retInt = 0;
    bool retBool = true;
    for (auto v : actions) {
        if (v[0] == "MyCircularQueue") {
            mcq = new MyCircularQueue(atoi(v[1].c_str()));
        } else if (v[0] == "Front") {
            retInt = mcq->Front();
            Output(retInt);
        } else if (v[0] == "Rear") {
            retInt = mcq->Rear();
            Output(retInt);
        } else if (v[0] == "enQueue") {
            retBool = mcq->enQueue(atoi(v[1].c_str()));
            Output(retBool);
        } else if (v[0] == "deQueue") {
            retBool = mcq->deQueue();
            Output(retBool);
        } else if (v[0] == "isEmpty") {
            retBool = mcq->isEmpty();
            Output(retBool);
        } else if (v[0] == "isFull") {
            retBool = mcq->isFull();
            Output(retBool);
        }
    }

    return 0;
}
