#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
#include "Types.hh"

using namespace std;

template <typename baseType>
void Output(baseType& value) {
    cout << value << endl;
};

template <typename baseType>
void Output(vector<baseType>& valueVec) {
    for (auto p : valueVec) {
        Output(p);
    }
}

template <typename baseType>
void Output(vector<vector<baseType>>& valueGrid) {
    cout << valueGrid.size() << endl;
    for (auto p : valueGrid) {
        cout << p.size();
        for (auto q : p) {
            cout << " " << q;
        }
        cout << endl;
    }
}

template <>
void Output(bool& value) {
    cout << (value?"true":"false") << endl;
}

template <typename baseType>
void Output(BaseListNode<baseType>* node) {
    BaseListNode<baseType>* cur = node;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

template <typename baseType>
void Output(BaseTreeNode<baseType>* node) {
    if (NULL == node) return;
    int size = 0, curIndex = 0;
    vector<BaseTreeNode<baseType>*> treeVec;
    treeVec.push_back(node);
    ++size;
    while (curIndex < size) {
        BaseTreeNode<baseType>* cur = treeVec[curIndex];
        cout << curIndex << "\t" << cur->val;
        if (cur->left != NULL) {
            treeVec.push_back(cur->left);
            cout << "\t" << size;
            ++size;
        } else {
            cout << "\tn";
        }
        if (cur->right != NULL) {
            treeVec.push_back(cur->right);
            cout << "\t" << size << endl;
            ++size;
        } else {
            cout << "\tn" << endl;
        }
        ++curIndex;
    }
}

template <typename baseType>
void Output(ArrayTreeNode<baseType>* node) {
    if (NULL == node) return;
    int size = 0, curIndex = 0, i;
    vector<ArrayTreeNode<baseType>*> treeVec;
    treeVec.push_back(node);
    ++size;
    while (curIndex < size) {
        ArrayTreeNode<baseType>* cur = treeVec[curIndex];
        cout << curIndex << "\t" << cur->val << "\t" << cur->children.size();
        for (i = 0; i < cur->children.size(); ++i) {
            treeVec.push_back(cur->children[i]);
            cout << "\t" << size;
            ++size;
        }
        cout << endl;
        ++curIndex;
    }
}

#endif
