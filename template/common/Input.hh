#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include "Types.hh"

using namespace std;

template <typename baseType>
void Input(baseType& value) {
    cin >> value;
};

template <typename baseType>
void Input(vector<baseType>& valueVec) {
    baseType value;
    int n;
    cin >> n;
    while (n-- > 0) {
        Input(value);
        valueVec.push_back(value);
    }
}

template <>
void Input(vector<string>& valueVec) {
    string value;
    int n;
    cin >> n;
    // finish the last line with n
    getline(cin, value);
    while (n-- > 0) {
        getline(cin, value);
        valueVec.push_back(value);
    }
}

template <typename baseType>
void Input(vector<vector<baseType>>& valueGrid) {
    int n;
    vector<baseType> valueVec;
    cin >> n;
    while (n-- > 0) {
        valueVec.clear();
        Input(valueVec);
        valueGrid.push_back(valueVec);
    }
}

template <>
void Input(string& value) {
    getline(cin, value);
}

template <typename baseType>
void Input(MyTreeNode<baseType>*& root) {
    unsigned int n;
    unsigned int i;
    unsigned int index;
    baseType value;
    string lindex;
    string rindex;
    unsigned int leftIndex;
    unsigned int rightIndex;

    cin >> n;
    vector<MyTreeNode<baseType>*> nodes(n, NULL);
    i = 0;
    while (i < n) {
        cin >> index;
        cin >> value;
        cin >> lindex;
        cin >> rindex;
        assert(i == index);

        if (nodes[i] == NULL) {
            nodes[i] = new MyTreeNode(value);
        } else {
            nodes[i]->val = value;
        }
        if (lindex != std::string("n")) {
            leftIndex = atoi(lindex.c_str());
            assert(leftIndex < n);
            if (nodes[leftIndex] == NULL) {
                nodes[leftIndex] = new MyTreeNode(0);
            }
            nodes[i]->left = nodes[leftIndex];
        }
        if (rindex != std::string("n")) {
            rightIndex = atoi(rindex.c_str());
            assert(rightIndex < n);
            if (nodes[rightIndex] == NULL) {
                nodes[rightIndex] = new MyTreeNode(0);
            }
            nodes[i]->right = nodes[rightIndex];
        }
        ++i;
    }

    root = nodes[0];
}

template <>
void Input(bool& value) {
    int valueInt;
    cin >> valueInt;
    value = (valueInt == 0) ? false : true;
}

template <typename baseType>
struct BaseListNode {
    baseType val;
    BaseListNode *next;
    BaseListNode(baseType x) : val(x), next(NULL) {}
};

template <typename baseType>
void Input(BaseListNode<baseType>*& head) {
    vector<baseType> valueVec;
    Input(valueVec);
    BaseListNode<baseType>* tail = NULL;
    for (auto value : valueVec) {
        if (tail == NULL) {
            head = new BaseListNode(value);
            tail = head;
        } else {
            tail->next = new BaseListNode(value);
            tail = tail->next;
        }
    }
}
