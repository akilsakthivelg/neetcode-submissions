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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        auto t = head;
        auto n = t->next;
        ListNode* p = NULL;
        t->next=p;
        p=t;
        while (n!=NULL) {
            t=n;
            n=n->next;
            t->next=p;
            p=t;
        }
        return t;
        
    }
};
