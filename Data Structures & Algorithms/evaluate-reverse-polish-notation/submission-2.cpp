class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto e:tokens) {
            if (e=="+" || e=="-" || e=="*" || e=="/") {
                if (stk.size()<2) return -1;
                int a=stk.top();
                stk.pop();
                int b=stk.top();
                stk.pop();
                if (e=="+") stk.push(b+a);
                else if (e=="-") stk.push(b-a);
                else if (e=="*") stk.push(b*a);
                else stk.push(b/a);
            } else {
                stk.push(stoi(e));
            }
        }
        return stk.top();
    }
};
