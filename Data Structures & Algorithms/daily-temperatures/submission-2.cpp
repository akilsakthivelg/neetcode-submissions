class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ans;
        stack<int> stk;
        for (int i=t.size()-1;i>=0;i--) {
            while (!stk.empty() && t[stk.top()]<=t[i]) {
                stk.pop();
            }
            if (stk.empty()) ans.push_back(0);
            else ans.push_back(stk.top()-i);
            stk.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
