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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=NULL;
        ListNode* last=NULL;
        while (list1 && list2) {
            ListNode* temp;
            if (list1->val <= list2->val) {
                temp=list1;
                list1=list1->next;
            } else {
                temp=list2;
                list2=list2->next;
            }
            temp->next=NULL;
            if (ans==NULL) {
                ans=temp;
                last=ans;
            } else {
                last->next=temp;
                last=last->next;
            }
        }
        if (list1!=NULL) {
            if (!ans) ans=list1;
            else last->next=list1;
        }
        else {
            if (!ans) ans=list2;
            else last->next=list2;
        }
        return ans;
    }
};
