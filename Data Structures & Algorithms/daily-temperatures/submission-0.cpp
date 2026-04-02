class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> next_max(T.size(),0);
        for (int i=T.size()-1;i>=0;i--) {
            while (!stk.empty() && T[i]>=T[stk.top()]) stk.pop();
            if (stk.empty()) next_max[i]=-1;
            else next_max[i]=stk.top();
            stk.push(i);
        }
        vector<int> ans;
        for (int i=0;i<T.size();i++) {
            ans.push_back(next_max[i]==-1?0:next_max[i]-i);
        }
        return ans;
    }
};
