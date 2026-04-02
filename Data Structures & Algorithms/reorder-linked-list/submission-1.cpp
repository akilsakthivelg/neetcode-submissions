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
    void reverse(ListNode* &head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void reorderList(ListNode* head) {
        int l=0;
        auto t=head;
        
        while (t) {
            l++;
            t=t->next;
        }
        t=head;
        for (int i=0;i<l/2;i++) {
            t=t->next;
        }
        auto l1=head;
        auto l2 = t->next;
        t->next=NULL;
        reverse(l2);
        while (l1 && l2) {
            auto t1=l1->next;
            auto t2=l2->next;
            l2->next=l1->next;
            l1->next=l2;
            l1=t1;
            l2=t2;
        }
    }
};
