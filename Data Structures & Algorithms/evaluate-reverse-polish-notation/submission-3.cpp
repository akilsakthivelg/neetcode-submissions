class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto x:tokens) {
            if (x.size()==1 && (x=="+" || x=="-" || x=="*" || x=="/")) {
                int b=stk.top();
                stk.pop();
                int a=stk.top();
                stk.pop();
                if (x=="+") stk.push(a+b);
                if (x=="-") stk.push(a-b);
                if (x=="*") stk.push(a*b);
                if (x=="/") stk.push(a/b);
            } else stk.push(stoi(x));
        }
        return stk.top();
    }
};
