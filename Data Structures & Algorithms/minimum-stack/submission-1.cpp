class MinStack {
public:
    stack<pair<int,int>> stk;
    
    MinStack() {
    }
    
    void push(int val) {
        int minimum = min(val,(stk.empty()?val:stk.top().second));
        stk.push({val,minimum});
    }
    
    void pop() {
        if (stk.empty()) return;
        stk.pop();
    }
    
    int top() {
        if (stk.empty()) return -1;
        return stk.top().first;
    }
    
    int getMin() {
        if (stk.empty()) return -1;
        return stk.top().second;
    }
};
