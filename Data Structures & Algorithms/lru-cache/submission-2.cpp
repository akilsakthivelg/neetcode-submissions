struct Node {
    int key;
    int val;

    Node *next;
    Node *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x,int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    // Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:

    unordered_map<int,Node*> m;
    int c;
    Node *head = nullptr, *l = nullptr;
    
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if (m.find(key)!=m.end()) {
            if (m[key]!=l) {
                if (m[key]==head) head=head->next;
                if (m[key]->prev) m[key]->prev->next=m[key]->next;
                if (m[key]->next) m[key]->next->prev=m[key]->prev;
                l->next=m[key];
                m[key]->prev=l;
                l=l->next;
            }
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key)!=m.end()) {
            m[key]->val=value;
            get(key);
            return;
        }
        if (m.size()==c) {
            m.erase(head->key);
            if (l==head) l=NULL;
            head=head->next;
            if (head!=NULL) head->prev=NULL;
        }
        Node* t = new Node(key,value);
        m[key]=t;
        if (head==NULL) {
            head=l=t;
        } else {
            l->next=t;
            t->prev=l;
            l=l->next;
        }
    }
};
