#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseListNode<int> ListNode;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        header = new ListNode(0);
        tail = header;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) return -1;
        ListNode* before = getBefore(index);
        return (before == NULL) ? -1 : before->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val, header->next);
        header->next = newNode;
        if (tail == header) {
            tail = newNode;
        }
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail->next = new ListNode(val, NULL);
        tail = tail->next;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < size) {
            ListNode* before = getBefore(index);
            ListNode* newNode = new ListNode(val, before->next);
            before->next = newNode;
            ++size;
        } else if (index == size) {
            addAtTail(val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < size) {
            ListNode* before = getBefore(index);
            ListNode* cur = before->next;
            before->next = cur->next;
            if (tail == cur) tail = before;
            delete cur;
            --size;
        }
    }

    void show() {
        Output(header);
    }

private:
    ListNode* getBefore(int index) {
        int i = 0;
        ListNode* before = header;
        while (i < index) {
            ++i;
            before = before->next;
        }
        return before;
    }

private:
   int size;
   ListNode* header;
   ListNode* tail;
};

int main(int argc, char* argv[])
{
    // input
    MyLinkedList* obj = new MyLinkedList();
    vector<vector<int>> actions;
    Input(actions);
    
    // output
    for (auto action : actions) {
        switch(action[0]) {
        case 0:
            obj->addAtHead(action[1]);
            break;
        case 1:
            obj->addAtTail(action[1]);
            break;
        case 2:
            obj->addAtIndex(action[1], action[2]);
            break;
        case 3:
            obj->deleteAtIndex(action[1]);
            break;
        default:
            cout << obj->get(action[1]) << endl;
        }
    }

    return 0;
}
