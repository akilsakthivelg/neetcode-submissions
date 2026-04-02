class MinStack {
public:

    vector<pair<int,int>> stk;
    int t;
    MinStack() {
        t=-1;
    }
    
    void push(int val) {
        stk.push_back({val,stk.size()?min(val,stk[t].second):val});
        t++;
    }
    
    void pop() {
        stk.pop_back();
        t--;
    }
    
    int top() {
        return stk[t].first;
    }
    
    int getMin() {
        if (t==-1) return -1;
        return stk[t].second;
    }
};
