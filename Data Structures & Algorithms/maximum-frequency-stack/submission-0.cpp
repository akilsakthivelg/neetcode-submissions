class FreqStack {
public:
    unordered_map<int,int> m;
    vector<stack<int>> stks;

    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        int c = m[val];
        while (stks.size()<=c) stks.push_back(stack<int>());
        stks[c].push(val);
    }
    
    int pop() {
        int val = stks.back().top();
        stks.back().pop();
        if (stks.back().size()==0) stks.pop_back();
        m[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */