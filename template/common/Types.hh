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
    baseType val;
    BaseTreeNode<baseType>* left;
    BaseTreeNode<baseType>* right;
    BaseTreeNode(const baseType pval,
               BaseTreeNode<baseType>* pleft = NULL,
               BaseTreeNode<baseType>* pright = NULL)
        : val(pval), left(pleft), right(pright) {}
};

#endif
