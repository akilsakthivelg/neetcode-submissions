class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> ls(n),rs(n);
        stack<int> l,r;
        for (int i=0;i<n;i++) {
            while (!l.empty() && arr[l.top()] >= arr[i]) l.pop();
            if (!l.empty()) ls[i]=l.top();
            else ls[i]=-1;
            l.push(i);
        }
        for (int i=n-1;i>=0;i--) {
            while (!r.empty() && arr[r.top()] >= arr[i]) r.pop();
            if (!r.empty()) rs[i]=r.top();
            else rs[i]=n;
            r.push(i);
        }
        int ans=0;
        for (int i=0;i<n;i++) {
            ans=max(ans,(rs[i]-ls[i]-1)*arr[i]);
        }
        return ans;
    }
};
