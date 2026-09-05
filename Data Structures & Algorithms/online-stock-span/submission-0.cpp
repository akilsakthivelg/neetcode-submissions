class StockSpanner {
public:
    int i=0;
    stack<pair<int,int>> stk; 
    StockSpanner() {
    }
    
    int next(int price) {
        i++;
        while (!stk.empty() && stk.top().first<=price) stk.pop();
        int ans;
        if (stk.empty()) ans=i;
        else ans=i-stk.top().second;
        stk.push({price,i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */