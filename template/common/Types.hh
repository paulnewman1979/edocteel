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
struct MyTreeNode {
    baseType val;
    MyTreeNode<baseType>* left;
    MyTreeNode<baseType>* right;
    MyTreeNode(const baseType pval,
               MyTreeNode<baseType>* pleft = NULL,
               MyTreeNode<baseType>* pright = NULL)
        : val(pval), left(pleft), right(pright) {}
};

#endif
