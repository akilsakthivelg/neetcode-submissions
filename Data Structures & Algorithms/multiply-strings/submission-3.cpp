class Solution {
public:

    string sum(string num1,string num2) {
        string ans="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int i=0;
        int j=0;
        int c=0;
        int n=num1.size();
        int m=num2.size();
        while (i<n || j<m) {
            int v;
            if (i<n && j<m) {
                v=(num1[i]-'0'+num2[j]-'0'+c);
            } else if (i<n) {
                v=(num1[i]-'0'+c);
            } else {
                v=(num2[j]-'0'+c);
            }
            c=v/10;
            v%=10;
            ans+=(to_string(v));
            i++;
            j++;
        }
        if (c>0) ans+=(to_string(c));
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string mul(string num,char c) {
        string ans="";
        int carry=0;
        reverse(num.begin(),num.end());
        for (auto x:num) {
            int v=(x-'0')*(c-'0')+carry;
            carry=v/10;
            v%=10;
            ans+=(to_string(v));
        }
        if (carry>0) ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1,num2);
        string ans="";
        string z="";
        for (int i=num2.size()-1;i>=0;i--) {
            string val=mul(num1,num2[i]);
            ans=sum(ans,val+z);
            z+="0";
        }
        while (ans[0]=='0' && ans.size()>1) {
            ans=ans.substr(1,ans.size()-1);
        }
        return ans;
     }
};
