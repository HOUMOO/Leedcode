//
// Created by houmo on 19-3-19.
//
/*
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
 */

#include "Solution_25.h"

ListNode *Solution_25::reverseKGroup(ListNode *head, int k) {
    ListNode * first;
    ListNode * first_pre = NULL;
    ListNode * last;
    ListNode * last_next;
    ListNode * p;
    ListNode * p_next;
    ListNode * p_before;

    ListNode * NewLink;
    ListNode * walker=head;

    if(k==1){
        return  head;
    }
    while (walker != NULL){
        first = walker;
        int toEnd = 0;
        for(int i=1; i<k; i++){
            walker = walker->next;
            if(walker == NULL){
                toEnd = 1;
                break;
            }
        }
        if(toEnd == 1){
            if(first_pre!=NULL){
                first_pre->next = first;
                return NewLink;
            } else{
                return head;
            }
        }
        last = walker;
//        cout << last->val << endl;
        last_next = last->next;

        p = first->next;
        p_next = p->next;
        p->next = first;
        while(p != last){
            p_before = p;
            p = p_next;
            p_next = p->next;
            p->next = p_before;
        }

        if(first_pre == NULL){
            NewLink = last;
        } else{
            first_pre->next = last;
        }
        walker = last_next;
        first_pre = first;
        first->next = NULL;

//        ListNode * link = last;
//        while(link != NULL){
//            cout << link->val << endl;
//            link = link->next;
//        }
    }

    return NewLink;
}
