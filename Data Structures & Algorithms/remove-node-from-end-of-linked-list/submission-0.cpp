/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* t=head;
        while (t) {
            size++;
            t=t->next;
        }
        if (size<=1) return NULL;
        int del=size-n+1;
        t=head;
        if (del==1) return t->next;
        
        while (--del-1) {
            t=t->next;
        }
        t->next=t->next->next;
        return head;
    }
};
