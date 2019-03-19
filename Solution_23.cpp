//
// Created by houmo on 19-3-7.
//

/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */
#include "Solution_23.h"

ListNode *Solution_23::mergeKLists(vector<ListNode *> &lists) {
    for(int i=0;i<lists.size();i++) {
        if(lists[i]==NULL){
            lists.erase(lists.begin()+i);
            i--;
        }
    }

    ListNode * NewLink = new ListNode(0);
    ListNode * tail = NewLink;

    while (!lists.empty()){
        int min = lists[0]->val;
        int MinTempIndex = 0;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]->val < min){
                min = lists[i]->val;
                MinTempIndex = i;
            }
        }

        tail->next = lists[MinTempIndex];
        tail = tail->next;
        if(lists[MinTempIndex]->next!=NULL){
            lists[MinTempIndex] = lists[MinTempIndex]->next;
        }else{
            lists.erase(lists.begin()+MinTempIndex);
        }

    }


    return NewLink->next;
}
