//
// Created by houmo on 19-3-8.
//
/*
 *Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
#include "Solution_24.h"

ListNode *Solution_24::swapPairs(ListNode *head) {
    if(head==NULL){
        return head;
    }else if(head->next == NULL){
        return head;
    }else{
        ListNode * P2 = head;
        ListNode * P1 = head->next;

        ListNode * newHead = P1;
        ListNode * tail = newHead;
        ListNode * tempP2 = P1->next;
        tail->next = P2;
        tail = tail->next;

        P2 = tempP2;
        if(P2==NULL){
            tail->next = NULL;
            return newHead;
        }else{
            P1 = P2->next;
            while(P1!=NULL){
                tail->next = P1;
                tail = tail->next;
                tempP2 = P1->next;
                tail->next = P2;
                tail = tail->next;

                P2 = tempP2;
                if(P2==NULL){
                    break;
                }
                P1 = P2->next;

            }
            if(P1==NULL && P2!=NULL){
                tail->next = P2;
                tail = tail->next;
            }
            tail->next = NULL;
            return  newHead;
        }
    }

}
