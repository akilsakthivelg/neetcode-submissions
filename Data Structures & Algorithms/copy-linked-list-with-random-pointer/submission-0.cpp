/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node* > m;
        Node* t=head;
        Node* ans  = NULL, *l = NULL;
        while (t) {
            Node* a = new Node(t->val);
            if (ans) {
                l->next=a;
                l=l->next;
            } else {
                ans=l=a;
            }
            m[t]=a;
            t=t->next;
        }
        t=head;
        Node*p=ans;
        while (t) {
            if (t->random) 
                p->random = m[t->random];
            p=p->next;
            t=t->next;
        }
        return ans;
    }
};
