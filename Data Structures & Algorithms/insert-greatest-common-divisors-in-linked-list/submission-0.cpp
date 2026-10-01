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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next==nullptr) return head;
        ListNode* t=head;
        while (t->next) {
            int g=gcd(t->val,t->next->val);
            ListNode* p=t->next;
            t->next=new ListNode(g);
            t->next->next=p;
            t=p;
        }
        return head;
    }
};