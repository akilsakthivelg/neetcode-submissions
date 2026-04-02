class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> l,r;
        vector<int> lmin(n);
        vector<int> rmin(n);
        int ans=0;
        for (int i=0;i<n;i++) {
            while (!l.empty() && heights[l.top()]>=heights[i]) l.pop();
            if (l.empty()) lmin[i]=-1;
            else lmin[i]=l.top();
            l.push(i);
        }
        for (int i=n-1;i>=0;i--) {
            while (!r.empty() && heights[r.top()]>=heights[i]) r.pop();
            if (r.empty()) rmin[i]=n;
            else rmin[i]=r.top();
            r.push(i);
        }
        for (int i=0;i<n;i++) {
            ans = max(ans,(rmin[i]-lmin[i]-1)*heights[i]);
        }
        return ans;
    }
};
