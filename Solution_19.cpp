//
// Created by houmo on 19-2-26.
//
/*
 * Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
 */
#include "Solution_19.h"

ListNode *Solution_19::removeNthFromEnd(ListNode *head, int n) {
    ListNode * p = head;
    ListNode * PreN = head;


    for(int i=0; i<n; i++){
        p = p->next;
    }

    if(p==NULL){
        head = head->next;
    } else{
        while(p->next!=NULL && p!=NULL){
            p = p->next;
            PreN = PreN->next;
        }
        PreN->next = PreN->next->next;
    }



    return head;

}
