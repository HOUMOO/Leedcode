//
// Created by houmo on 19-2-28.
//
/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */
#include "Solution_21.h"



ListNode *Solution_21::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode * NewLink = new ListNode(0);
    ListNode * tail = NewLink;
    ListNode * P1 = l1;
    ListNode * P2 = l2;

    while(P1 != NULL && P2 != NULL){
        if(P1->val < P2->val){
            tail ->next = P1;
            tail = tail->next;
            P1 = P1->next;
        } else{
            tail -> next = P2;
            tail = tail->next;
            P2 = P2->next;
        }
    }
    if(P1 != NULL){
        tail->next = P1;
    } else{
        tail->next = P2;
    }

//    ListNode * p = NewLink->next;
//    while(p!=NULL){
//        cout << p->val << endl;
//        p = p->next;
//    }

    return NewLink->next;
}
