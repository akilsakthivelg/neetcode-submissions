class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int s=arr[0][0];
        int e=arr[0][1];
        for (auto x:arr) {
            if (x[0]<=e) e=max(e,x[1]);
            else {
                ans.push_back({s,e});
                s=x[0];
                e=x[1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};
