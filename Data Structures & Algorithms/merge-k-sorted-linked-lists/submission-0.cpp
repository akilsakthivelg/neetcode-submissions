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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<tuple<int,ListNode*>,vector<tuple<int,ListNode*>>,greater<tuple<int,ListNode*>>> pq;
        ListNode *head=NULL,*last=NULL;
        int n=lists.size();
        for (int i=0;i<n;i++) {
            if (lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        while (!pq.empty()) {
            auto [val,node] = pq.top();
            pq.pop();
            if (head) {
                last->next=node;
                last=last->next;
            } else {
                head=last=node;
            }
            if (node->next) pq.push({node->next->val,node->next});
        }
        return head;
    }
};
