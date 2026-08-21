class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        for (auto x:operations) {
            if (x=="+") {
                if (stk.size()>=2) {
                    int a = stk.top();stk.pop();
                    int b = a+stk.top();
                    stk.push(a);
                    stk.push(b);
                }
            } else if (x=="D") {
                if (stk.size()) {
                    stk.push(stk.top()*2);
                }
            } else if (x=="C") {
                if (stk.size()) stk.pop();
            } else {
                stk.push(stoi(x));
            }
        }
        int ans=0;
        while (!stk.empty()) {
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};