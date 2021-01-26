#ifndef __TYPES_HH__
#define __TYPES_HH__

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
template <typename baseType>
struct BaseListNode {
    baseType val;
    BaseListNode* next;
    BaseListNode(baseType pval,
                 BaseListNode<baseType>* pnext = NULL)
        : val(pval), next(pnext) {}
};

/**
 * Definition for a binary tree node.
 */
template <typename baseType>
struct BaseTreeNode {
    BaseTreeNode() {}
    BaseTreeNode(const baseType pval,
               BaseTreeNode<baseType>* pleft = NULL,
               BaseTreeNode<baseType>* pright = NULL)
        : val(pval), left(pleft), right(pright) {}

    baseType val;
    BaseTreeNode<baseType>* left;
    BaseTreeNode<baseType>* right;
};

template <typename baseType>
struct ArrayTreeNode {
    ArrayTreeNode() {}
    ArrayTreeNode(baseType _val) { val = _val; }
    ArrayTreeNode(baseType _val, vector<ArrayTreeNode*> _children) {
        val = _val;
        children = _children;
    }

    baseType val;
    vector<ArrayTreeNode*> children;
};

#endif
