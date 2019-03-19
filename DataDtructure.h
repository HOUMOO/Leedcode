//
// Created by houmo on 19-2-26.
//

#ifndef LEETCODE_DATADTRUCTURE_H
#define LEETCODE_DATADTRUCTURE_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct binary_tree_node{
    char elem;

    struct binary_tree_node * left;
    struct binary_tree_node * right;
}* binary_tree;

#endif //LEETCODE_DATADTRUCTURE_H
