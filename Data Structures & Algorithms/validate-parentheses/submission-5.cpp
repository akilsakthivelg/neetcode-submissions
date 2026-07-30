class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        int i=0;

        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);

            else if(s[i]=='}'){
                if(st.empty() || st.top()!='{') return false;

                st.pop();
            }
            else if(s[i]==')'){
                if(st.empty() || st.top()!='(') return false;
                st.pop();
            }
            else if(s[i]==']'){
                if(st.empty() || st.top()!='[') return false;
                st.pop();
            }

            i++;
        }
        if(st.empty()) return true;
        return false;
    }
};
