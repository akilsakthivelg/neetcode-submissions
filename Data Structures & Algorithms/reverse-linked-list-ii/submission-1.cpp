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
    ListNode* reverse(ListNode* h) {
        ListNode* prev = NULL;
        ListNode* curr = h;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (l==r) return head;
        ListNode* t = NULL;
        ListNode* p = head;
        int k=l-1;
        while (k--) {
            if(t) t=t->next;
            else t=head;
        }
        k=r;
        ListNode* b = NULL;
        while (k--) {
            b=p;
            p=p->next;
        }
        b->next=NULL;
        ListNode* m = t ? reverse(t->next) : reverse(head);
        if (t) t->next=m;
        if (t==NULL) head=m;
        while (m->next) {
            m=m->next;
        }
        m->next=p;
        return head;

    }
};