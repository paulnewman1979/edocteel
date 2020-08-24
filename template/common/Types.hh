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
    BaseListNode *next;
    BaseListNode(baseType x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 */
template <typename baseType>
struct MyTreeNode {
    baseType val;
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode(baseType x) : val(x), left(NULL), right(NULL) {}
};

#endif
