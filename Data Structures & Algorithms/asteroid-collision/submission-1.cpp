class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (auto &x:asteroids) {
            bool wantToInsert = true;
            while (!stk.empty() && stk.top()>0 && x<0) {
                if (abs(stk.top()) == abs(x)) {
                    stk.pop();
                    wantToInsert = false;
                    break;
                } else if (abs(stk.top()) > abs(x)) {
                    wantToInsert = false;
                    break;
                } else {
                    stk.pop();
                }
            }
            if (wantToInsert) stk.push(x);
        }
        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};