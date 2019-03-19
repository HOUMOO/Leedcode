//
// Created by houmo on 19-1-9.
//

#include "Solution_2.h"

/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example:

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode *Solution_2::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode * Answer = new ListNode(0);
    ListNode * tail = Answer;
    int carryBit = 0;
    ListNode * P1 = l1;
    ListNode * P2 = l2;
    
    while(P1!=NULL && P2!=NULL){
        tail->next = new ListNode((P1->val + P2->val + carryBit)%10);
        carryBit = (P1->val + P2->val + carryBit)/10;
        tail = tail->next;
        P1 = P1->next;
        P2 = P2->next;
    }
    if(P1!=NULL){
        while(P1){
            tail->next = new ListNode((P1->val + carryBit)%10);
            carryBit = (P1->val + carryBit)/10;
            tail = tail->next;
            P1 = P1->next;
        }
    }
    if(P2!=NULL){
        while(P2){
            tail->next = new ListNode((P2->val + carryBit)%10);
            carryBit = (P2->val + carryBit)/10;
            tail = tail->next;
            P2 = P2->next;
        }
    }
    if(carryBit){
        tail->next = new ListNode(1);
    }

    return Answer->next;
}
