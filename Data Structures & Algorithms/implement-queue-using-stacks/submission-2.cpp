class MyQueue {
    stack<int> stk;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> stk1;
        while (!stk.empty()) {
            stk1.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while (!stk1.empty()) {
            stk.push(stk1.top());
            stk1.pop();
        }

    }
    
    int pop() {
        if (stk.size()==0) return -1;
        int x = stk.top();
        stk.pop();
        return x;
    }
    
    int peek() {
        if (stk.size()==0) return -1;
        return stk.top();
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */