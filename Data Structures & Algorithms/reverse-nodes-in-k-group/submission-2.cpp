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
        ListNode* c=h;
        ListNode* p=NULL;
        ListNode* n=NULL;
        while (c) {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }

    ListNode* reverseKGroup(ListNode* h, int k) {
        ListNode* ans=NULL;
        ListNode* l=NULL;
        ListNode* n=NULL;
        n=h;
        while (h) {
            auto t=h;
            bool f=false;
            for (int i=0;i<k-1;i++) {
                if (h->next) h=h->next;
                else {
                    f=true;
                    break;
                }
            }
            if (!f) {
                n=h->next;
                h->next=NULL;
                h=n;
                t = reverse(t);
            } else {
                t=t;
            }
            if (ans) {
                l->next=t;
                while (l->next) l=l->next;
            } else {
                ans=t;
                l=ans;
                while (l->next) l=l->next;
            }
            if (f) break;
        }
        return ans;
    }
};
