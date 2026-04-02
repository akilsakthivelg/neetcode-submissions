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

    int len(ListNode* l) {
        int c=0;
        while (l && ++c) l=l->next;
        return c;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (len(l2)>len(l1)) swap(l1,l2);
        ListNode* t=l1;
        int r=0;
        while (t) {
            int t1 = t->val;
            int t2 = (l2) ? l2->val : 0;
            t->val=(t1+t2+r)%10;
            r=(t1+t2+r)/10;
            t=t->next;
            if (l2) l2=l2->next;
        }
        if (r!=0) {
            t=l1;
            while (t->next) t=t->next;
            t->next=new ListNode(r);
        }
        return l1;
    }
};
